/*
*
* This file is part of QMapControl,
* an open-source cross-platform map widget
*
* Copyright (C) 2025 masc4ii
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with QMapControl. If not, see <http://www.gnu.org/licenses/>.
*
* Original program URL   : http://qmapcontrol.sourceforge.net/
*
*/

#include "LayerHillshading.h"

// STL includes.
#include <cmath>
#include <QtMath>

// Local includes.
#include "ImageManager.h"
#include <QMapControl/MapAdapterMapterhorn.h>

namespace qmapcontrol
{
    LayerHillshading::LayerHillshading(const std::string& name, const int& zoom_minimum, const int& zoom_maximum, QObject* parent)
        : Layer(LayerType::LayerHillshading, name, zoom_minimum, zoom_maximum, parent),
        m_mapadapter(std::make_shared<MapAdapterMapterhorn>()),
        m_light_direction(180),
        m_light_height(20),
        m_opacity(90),
        m_enabled(true)
    {

    }

    void LayerHillshading::setLightDirection(const int& degree)
    {
        if (degree < 0)
            m_light_direction = 0;
        else if (degree > 359)
            m_light_direction = 359;
        else
            m_light_direction = degree;

        // Emit to redraw layer.
        emit requestRedraw();
    }

    int LayerHillshading::lightDirection() const
    {
        return m_light_direction;
    }

    void LayerHillshading::setLightHeight(const int &height)
    {
        if (height < 1)
            m_light_height = 1;
        else if (height > 22)
            m_light_height = 22;
        else
            m_light_height = height;
        
        // Emit to redraw layer.
        emit requestRedraw();
    }

    int LayerHillshading::lightHeight() const
    {
        return m_light_height;
    }

    void LayerHillshading::setOpacity(const uint8_t &opacity)
    {
        if (opacity > 100)
            m_opacity = 100;
        else
            m_opacity = opacity;

        // Emit to redraw layer.
        emit requestRedraw();
    }

    uint8_t LayerHillshading::opacity() const
    {
        return m_opacity;
    }

    void LayerHillshading::setEnabled(bool on)
    {
        m_enabled = on;

        // Emit to redraw layer.
        emit requestRedraw();
    }

    bool LayerHillshading::isEnabled()
    {
        return m_enabled;
    }

    bool LayerHillshading::mousePressEvent(const QMouseEvent* /*mouse_event*/, const PointWorldCoord& /*mouse_point_coord*/, const int& /*controller_zoom*/) const
    {
        // Do nothing.
        return false;
    }

    void LayerHillshading::draw(QPainter& painter, const RectWorldPx& backbuffer_rect_px, const int& controller_zoom) const
    {
        if(!m_enabled)
            return;

        // Multiply onto map
        painter.setCompositionMode(QPainter::CompositionMode_Multiply);
        painter.setOpacity(m_opacity / 100.0);

        // Gain a read lock to protect the map adapter.
        QReadLocker locker(&m_mapadapter_mutex);

        // Check the layer is visible and a map adapter is set.
        if(isVisible(controller_zoom) && m_mapadapter != nullptr)
        {
            // Check we have a base url to fetch map!
            if(m_mapadapter->getBaseUrl().isEmpty())
            {
                // We cannot fetch map tiles as no base url set!
                qDebug() << "Map adapater base url is empty!";
            }
            else
            {
                // The current tile size.
                const QSizeF tile_size_px(ImageManager::get().tileSizePx(), ImageManager::get().tileSizePx());

                // Calculate the tiles to draw.
                const int furthest_tile_left = std::floor(backbuffer_rect_px.leftPx() / tile_size_px.width());
                const int furthest_tile_top = std::floor(backbuffer_rect_px.topPx() / tile_size_px.height());
                const int furthest_tile_right = std::floor(backbuffer_rect_px.rightPx() / tile_size_px.width());
                const int furthest_tile_bottom = std::floor(backbuffer_rect_px.bottomPx() / tile_size_px.height());

                // Loop through the tiles to draw (left to right).
#pragma parallel for collapse(2)
                for(int i = furthest_tile_left; i <= furthest_tile_right; ++i)
                {
                    // Loop through the tiles to draw (top to bottom).
                    for(int j = furthest_tile_top; j <= furthest_tile_bottom; ++j)
                    {
                        // Check the tile is valid.
                        if(m_mapadapter->isTileValid(i, j, controller_zoom))
                        {
                            // Calculate the top left point.
                            const PointWorldPx top_left_px(i * tile_size_px.width(), j * tile_size_px.height());

                            // Draw the tile.
                            painter.drawPixmap(top_left_px.rawPoint(), render(ImageManager::get().getImage(m_mapadapter->tileQuery(i, j, controller_zoom)), controller_zoom));
                        }
                    }
                }

                // Prefetch the next set of rows/column tiles (ready for when the user starts panning).
                const int prefetch_tile_left = furthest_tile_left - 1;
                const int prefetch_tile_top = furthest_tile_top - 1;
                const int prefetch_tile_right = furthest_tile_right + 1;
                const int prefetch_tile_bottom = furthest_tile_bottom + 1;

                // Fetch the top/bottom rows.
                for (int i = prefetch_tile_left; i <= prefetch_tile_right; ++i)
                {
                    // Top row - check the tile is valid.
                    if(m_mapadapter->isTileValid(i, prefetch_tile_top, controller_zoom))
                    {
                        // Prefetch the tile.
                        ImageManager::get().prefetchImage(m_mapadapter->tileQuery(i, prefetch_tile_top, controller_zoom));
                    }

                    // Bottom row - check the tile is valid.
                    if(m_mapadapter->isTileValid(i, prefetch_tile_bottom, controller_zoom))
                    {
                        // Prefetch the tile.
                        ImageManager::get().prefetchImage(m_mapadapter->tileQuery(i, prefetch_tile_bottom, controller_zoom));
                    }
                }

                // Fetch the left/right columns.
                for (int j = prefetch_tile_top; j <= prefetch_tile_bottom; ++j)
                {
                    // Left column - check the tile is valid.
                    if(m_mapadapter->isTileValid(prefetch_tile_left, j, controller_zoom))
                    {
                        // Prefetch the tile.
                        ImageManager::get().prefetchImage(m_mapadapter->tileQuery(prefetch_tile_left, j, controller_zoom));
                    }

                    // Right column - check the tile is valid.
                    if(m_mapadapter->isTileValid(prefetch_tile_right, j, controller_zoom))
                    {
                        // Prefetch the tile.
                        ImageManager::get().prefetchImage(m_mapadapter->tileQuery(prefetch_tile_right, j, controller_zoom));
                    }
                }
            }
        }
    }

    QPixmap LayerHillshading::render(const QPixmap &pixmap, const int& controller_zoom) const
    {
        QImage img = pixmap.toImage().scaled(QSize(256,256));
        int w = img.width();
        int h = img.height();
        QVector<double> dem(w * h);
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                QColor c = img.pixelColor(x, y);
                dem[y*w + x] = -10000 + ((c.red()*256*256 + c.green()*256 + c.blue())*0.1);
            }
        }

        // Hillshade-Parameter
        double azimuthDeg = m_light_direction;
        double altitudeDeg = 50;
        double zFactor = 0.1;

        // Umrechnung in Radiant
        double azimuthRad = qDegreesToRadians(360.0 - azimuthDeg + 90.0);
        double altitudeRad = qDegreesToRadians(altitudeDeg);

        // Lichtvektor
        double lx = cos(altitudeRad) * cos(azimuthRad);
        double ly = cos(altitudeRad) * sin(azimuthRad);
        double lz = sin(altitudeRad);

        // Ausgabe-Bild
        QImage hillshade(w, h, QImage::Format_Grayscale8);
        hillshade.fill(0);

        // Pixelabstand (für WebMercator egal → relativ)
        double cellSize = std::pow(10.0, (16.0 - controller_zoom) / 4.0) * m_light_height / 10.0;

        for (int y = 1; y < h - 1; ++y) {
            for (int x = 1; x < w - 1; ++x) {

                // Horn-Gradienten
                double dzdx =
                    ((dem[(y-1)*w + (x+1)] + 2*dem[y*w + (x+1)] + dem[(y+1)*w + (x+1)]) -
                     (dem[(y-1)*w + (x-1)] + 2*dem[y*w + (x-1)] + dem[(y+1)*w + (x-1)]))
                    / (8.0 * cellSize);

                double dzdy =
                    ((dem[(y+1)*w + (x-1)] + 2*dem[(y+1)*w + x] + dem[(y+1)*w + (x+1)]) -
                     (dem[(y-1)*w + (x-1)] + 2*dem[(y-1)*w + x] + dem[(y-1)*w + (x+1)]))
                    / (8.0 * cellSize);

                dzdx *= zFactor;
                dzdy *= zFactor;

                // Normalenvektor
                double nx = -dzdx;
                double ny = -dzdy;
                double nz = 1.0;

                double len = sqrt(nx*nx + ny*ny + nz*nz);
                nx /= len;
                ny /= len;
                nz /= len;

                // Lambert-Shading
                double shade = nx*lx + ny*ly + nz*lz;
                shade = qBound(0.0, shade, 1.0);

                int gray = static_cast<int>(shade * 128.0 + 127);
                hillshade.setPixelColor(x, y, QColor(gray, gray, gray, 50));
            }
        }
        for (int y = 0; y < h; ++y) {
            hillshade.setPixelColor(0, y, hillshade.pixelColor(1, y));
            hillshade.setPixelColor(w-1, y, hillshade.pixelColor(w-2, y));
        }
        for (int x = 0; x < w; ++x) {
            hillshade.setPixelColor(x, 0, hillshade.pixelColor(x, 1));
            hillshade.setPixelColor(x, h-1, hillshade.pixelColor(x, h-2));
        }

        // Scaling 50%x50%
        //hillshade = hillshade.scaled(w / 2, h / 2, Qt::KeepAspectRatio, Qt::FastTransformation);

        // Ergebnis anzeigen
        return QPixmap::fromImage(hillshade);
    }
}
