#include "GeometryPointShapeScaled.h"

// STL includes.
#include <cmath>

// Local includes.
#include "Projection.h"

namespace qmapcontrol
{
    GeometryPointShapeScaled::GeometryPointShapeScaled(const qreal& longitude, const qreal& latitude, const QSizeF& base_size_px, const int& base_zoom, const int& zoom_minimum, const int& zoom_maximum)
        : GeometryPointShape(PointWorldCoord(longitude, latitude), base_size_px, zoom_minimum, zoom_maximum),
          m_base_zoom(base_zoom),
          m_nonlinear_zoom(1.0),
          m_draw_minimum_px(-1.0, -1.0),
          m_draw_maximum_px(-1.0, -1.0)
    {

    }

    GeometryPointShapeScaled::GeometryPointShapeScaled(const PointWorldCoord& point_coord, const QSizeF& base_size_px, const int& base_zoom, const int& zoom_minimum, const int& zoom_maximum)
        : GeometryPointShape(point_coord, base_size_px, zoom_minimum, zoom_maximum),
          m_base_zoom(base_zoom),
          m_nonlinear_zoom(1.0),
          m_draw_minimum_px(-1.0, -1.0),
          m_draw_maximum_px(-1.0, -1.0)
    {

    }

    const int& GeometryPointShapeScaled::baseZoom() const
    {
        // Return the base zoom level.
        return m_base_zoom;
    }

    void GeometryPointShapeScaled::setBaseZoom(const int& base_zoom)
    {
        // Set the base zoom level.
        m_base_zoom = base_zoom;

        // Update the shape.
        updateShape();
    }

    void GeometryPointShapeScaled::setNonlinearZoomFactor(double factor)
    {
        m_nonlinear_zoom = factor;
    }

    double GeometryPointShapeScaled::getNonlinearZoomFactor() const
    {
        return m_nonlinear_zoom;
    }

    const QSizeF& GeometryPointShapeScaled::drawMinimumPx() const
    {
        // Return the minimum size.
        return m_draw_minimum_px;
    }

    void GeometryPointShapeScaled::setDrawMinimumPx(const QSizeF& size_px)
    {
        // Set the minimum size.
        m_draw_minimum_px = size_px;

        // Update the shape.
        updateShape();
    }

    const QSizeF& GeometryPointShapeScaled::drawMaximumPx() const
    {
        // Return the maximum size.
        return m_draw_maximum_px;
    }

    void GeometryPointShapeScaled::setDrawMaximumPx(const QSizeF& size_px)
    {
        // Set the maximum size.
        m_draw_maximum_px = size_px;

        // Update the shape.
        updateShape();
    }

    RectWorldCoord GeometryPointShapeScaled::boundingBox(const int& controller_zoom) const
    {
        // Calculate the world point in pixels.
        const PointWorldPx point_px(projection::get().toPointWorldPx(coord(), controller_zoom));

        // Calculate the current size for this controller zoom.
        const QSizeF object_size_px(calculateGeometrySizePx(controller_zoom));

        // Calculate the top-left point.
        const PointWorldPx top_left_point_px(calculateTopLeftPoint(point_px, alignmentType(), object_size_px));

        // Calculate the bottom-right point.
        const PointWorldPx bottom_right_point_px(top_left_point_px.x() + object_size_px.width(), top_left_point_px.y() + object_size_px.height());

        // Return the converted coord points.
        return RectWorldCoord(projection::get().toPointWorldCoord(top_left_point_px, controller_zoom), projection::get().toPointWorldCoord(bottom_right_point_px, controller_zoom));
    }

    void GeometryPointShapeScaled::draw(QPainter &painter, const RectWorldCoord &backbuffer_rect_coord, const int &controller_zoom)
    {
        // Check the geometry is visible.
        if(isVisible(controller_zoom))
        {
            // Check if the bounding boxes intersect.
            const RectWorldCoord pixmap_rect_coord(boundingBox(controller_zoom));
            if(backbuffer_rect_coord.rawRect().intersects(pixmap_rect_coord.rawRect()))
            {
                // Calculate the pixmap rect to draw within.
                const RectWorldPx pixmap_rect_px(projection::get().toPointWorldPx(pixmap_rect_coord.topLeftCoord(), controller_zoom), projection::get().toPointWorldPx(pixmap_rect_coord.bottomRightCoord(), controller_zoom));


                qreal scale = pow(2.0, m_nonlinear_zoom * (controller_zoom - baseZoom()));

                // Translate to center point with required rotation.
                painter.translate(pixmap_rect_px.centerPx().rawPoint());
                painter.rotate(rotation());
                painter.scale(scale, scale);

                drawShape(painter, pixmap_rect_px);

                // Un-translate.
                painter.scale(1.0/scale, 1.0/scale);
                painter.rotate(-rotation());
                painter.translate(-pixmap_rect_px.centerPx().rawPoint());

                // Do we have a meta-data value and should we display it at this zoom?
                if(controller_zoom >= m_metadata_displayed_zoom_minimum && metadata(m_metadata_displayed_key).isNull() == false)
                {
                    /// @todo calculate correct alignment for metadata displayed offset.

                    // Draw the text next to the point with an offset.
                    painter.drawText(pixmap_rect_px.rawRect().topRight() + PointPx(m_metadata_displayed_alignment_offset_px, -m_metadata_displayed_alignment_offset_px).rawPoint(), metadata(m_metadata_displayed_key).toString());
                }
            }
        }
    }

    const QSizeF GeometryPointShapeScaled::calculateGeometrySizePx(const int& controller_zoom) const
    {
        // Get the object size (default to base size).
        QSizeF return_size_px(sizePx());

        // Do we have a base zoom set?
        if(m_base_zoom > 0)
        {
            // What is the difference between the base and current zoom.
            const int zoom_difference(m_base_zoom - controller_zoom);

            // Calculate the zoom width/height as a ratio of the zoom difference.
            return_size_px.setHeight(return_size_px.height() / std::pow(2.0, zoom_difference));
            return_size_px.setWidth(return_size_px.width() / std::pow(2.0, zoom_difference));

            // Do we have a minimum height draw size set?
            if(m_draw_minimum_px.height() > -1.0)
            {
                // Take the highest height.
                return_size_px.setHeight(std::max(return_size_px.height(), m_draw_minimum_px.height()));
            }

            // Do we have a minimum width draw size set?
            if(m_draw_minimum_px.width() > -1.0)
            {
                // Take the highest width.
                return_size_px.setWidth(std::max(return_size_px.width(), m_draw_minimum_px.width()));
            }

            // Do we have a maximum height draw size set?
            if(m_draw_maximum_px.height() > -1.0)
            {
                // Take the lowest height.
                return_size_px.setHeight(std::min(return_size_px.height(), m_draw_maximum_px.height()));
            }

            // Do we have a maximum width draw size set?
            if(m_draw_maximum_px.width() > -1.0)
            {
                // Take the lowest width.
                return_size_px.setWidth(std::min(return_size_px.width(), m_draw_maximum_px.width()));
            }
        }

        // Return the size.
        return return_size_px;
    }

}
