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

#pragma once

// Qt includes.
#include <QtCore/QObject>
#include <QtCore/QReadWriteLock>

// STL includes.
#include <memory>

// Local includes.
#include "qmapcontrol_global.h"
#include "Layer.h"
#include "MapAdapter.h"

namespace qmapcontrol
{
    //! Layer class
    /*!
     * Layer that can display a hillshading.
     *
     * @author masc4ii
     */
    class QMAPCONTROL_EXPORT LayerHillshading : public Layer
    {
        Q_OBJECT
    public:
        //! Layer constructor
        /*!
         * This is used to construct a layer.
         * @param name The name of the layer.
         * @param mapadapter The Map Adapter of the layer.
         * @param zoom_minimum The minimum zoom level to show this geometry at.
         * @param zoom_maximum The maximum zoom level to show this geometry at.
         * @param parent QObject parent ownership.
         */
        LayerHillshading(const std::string& name, const int& zoom_minimum = 0, const int& zoom_maximum = 17, QObject* parent = 0);

        //! Disable copy constructor.
        ///LayerHillshading(const LayerHillshading&) = delete; @todo re-add once MSVC supports default/delete syntax.

        //! Disable copy assignment.
        ///LayerHillshading& operator=(const LayerHillshading&) = delete; @todo re-add once MSVC supports default/delete syntax.

        //! Destructor.
        virtual ~LayerHillshading() { } /// = default; @todo re-add once MSVC supports default/delete syntax.

        /*! Sets the direction of the light source.
         * @param degree The direction in degrees (0..359).
         */
        void setLightDirection(const int& degree);

        /*! Returns the direction of the light source.
         * @return The direction in degrees (0..359).
         */
        int lightDirection() const;

        /*! Sets the height of the light source.
         * @param height The height (1..22).
         */
        void setLightHeight(const int& height);

        /*! Returns the height of the light source.
         * @return The height (1..22).
         */
        int lightHeight() const;

        /*! Sets the opacity of the hillshading layer.
         * @param opacity The opacity in percent (0..100).
         */
        void setOpacity(const uint8_t& opacity);

        /*! Returns the opacity of the hillshading layer.
         * @return The opacity in percent (0..100).
         */
        uint8_t opacity() const;

        /*! Enables or disables the hillshading layer.
         * @param on true to enable, false to disable.
         */
        void setEnabled(bool on);

        /*! Returns whether the hillshading layer is enabled.
         * @return true if enabled, false if disabled.
         */
        bool isEnabled();

        /*!
         * Handles mouse press events (such as left-clicking an item on the layer).
         * @param mouse_event The mouse event.
         * @param mouse_point_coord The mouse point on the map in coord.
         * @param controller_zoom The current controller zoom.
         */
        bool mousePressEvent(const QMouseEvent* mouse_event, const PointWorldCoord& mouse_point_coord, const int& controller_zoom) const final;

        /*!
         * Draws each map adapter and geometry to a pixmap using the provided painter.
         * @param painter The painter that will draw to the pixmap.
         * @param backbuffer_rect_px Only draw map tiles/geometries that are contained in the backbuffer rect (pixels).
         * @param controller_zoom The current controller zoom.
         */
        void draw(QPainter& painter, const RectWorldPx& backbuffer_rect_px, const int& controller_zoom) const final;

    private:
        /// Shader
        QPixmap render(const QPixmap& pixmap, const int &controller_zoom) const;

        /// The map adapter drawn by this layer.
        std::shared_ptr<MapAdapter> m_mapadapter;

        /// Mutex to protect map adapter.
        mutable QReadWriteLock m_mapadapter_mutex;

        /// Direction of light 0..359°
        int m_light_direction;

        /// Height of light 1..22
        int m_light_height;

        /// Opacity in % 0..100
        uint8_t m_opacity;

        /// Switch layer on/off
        bool m_enabled;
    };
}
