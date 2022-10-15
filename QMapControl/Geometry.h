/*
*
* This file is part of QMapControl,
* an open-source cross-platform map widget
*
* Copyright (C) 2007 - 2008 Kai Winter
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
* Contact e-mail: kaiwinter@gmx.de
* Program URL   : http://qmapcontrol.sourceforge.net/
*
*/

#pragma once

// Qt includes.
#include <QtCore/QObject>
#include <QtCore/QVariant>
#include <QtGui/QBrush>
#include <QtGui/QPainter>
#include <QtGui/QPen>

// STL includes.
#include <map>
#include <memory>
#include <string>

// Local includes.
#include "qmapcontrol_global.h"
#include "Point.h"

namespace qmapcontrol
{
    class LayerGeometry;

    //! Main class for objects that should be painted in maps.
    /*!
     * Geometry is the root class of the hierarchy. Geometry is an abstract (non-instantiable) class.
     *
     * All geometries can emit click events, if the containing layer receives click events (the default).
     *
     * This class and the derived classes Point and LineString are leant on the Simple
     * Feature Specification of the Open Geospatial Consortium.
     * @see www.opengeospatial.com
     *
     * @author Kai Winter <kaiwinter@gmx.de>
     * @author Chris Stylianou <chris5287@gmail.com>
     */
    class QMAPCONTROL_EXPORT Geometry : public QObject
    {
        friend class LayerGeometry;

        Q_OBJECT
    public:
        class AncillaryData {};

        //! Geometry types.
        enum class GeometryType
        {
            /// Geometry that represents a line string.
            GeometryLineString,
            /// Geometry that represents a point.
            GeometryPoint,
            /// Geometry that represents a polygon.
            GeometryPolygon,
            /// Geometry that manages a QWidget.
            GeometryWidget
        };

        //! Alignment types.
        enum class AlignmentType
        {
            /// Align on middle point.
            Middle,
            /// Align on top left point.
            TopLeft,
            /// Align on top right point.
            TopRight,
            /// Align on top middle point.
            TopMiddle,
            /// Align on bottom left point.
            BottomLeft,
            /// Align on bottom right point.
            BottomRight,
            /// Align on bottom middle point.
            BottomMiddle
        };

    protected:
        //! Constructor.
        /*!
         * This construct a Geometry.
         * @param geometry_type The geometry type.
         * @param zoom_minimum The minimum zoom level to show this geometry at.
         * @param zoom_maximum The maximum zoom level to show this geometry at.
         */
        Geometry(const GeometryType& geometry_type, const int& zoom_minimum = 0, const int& zoom_maximum = 17);

    public:
        //! Disable copy constructor.
        ///Geometry(const Geometry&) = delete; @todo re-add once MSVC supports default/delete syntax.

        //! Disable copy assignment.
        ///Geometry& operator=(const Geometry&) = delete; @todo re-add once MSVC supports default/delete syntax.

        //! Destructor.
        virtual ~Geometry() { } /// = default; @todo re-add once MSVC supports default/delete syntax.

        /*!
         * Fetches the zindex of the geometry
         * \return z-index of the geomety
         */
        int zIndex() const;

        /*!
         * Set the ZIndex of this geometry
         * \param z_index
         */
        void setZIndex(int z_index);

        /*!
         * Fetches the geometry type.
         * @return the geometry type.
         */
        const GeometryType& geometryType() const;

        /*!
         * Fetches whether the geometry is visible.
         * @param controller_zoom The current controller zoom.
         * @return whether the geometry is visible.
         */
        bool isVisible(const int& controller_zoom) const;

        /*!
         * Set the visibility of the geometry.
         * @param enabled Whether to make the geometry visible.
         */
        virtual void setVisible(const bool& enabled);

        /*!
         * Fetches the pen to draw the geometry with (outline).
         * @return the QPen to used for drawing.
         */
        const QPen& pen();

        /*!
         * Sets the pen to draw the geometry with (outline).
         * @param pen The QPen to used for drawing.
         */
        virtual void setPen(const std::shared_ptr<QPen>& pen);

        /*!
         * Sets the pen to draw the geometry with (outline).
         * @param pen The QPen to used for drawing.
         */
        virtual void setPen(const QPen& pen);

        /*!
         * Fetches the brush to draw the geometry with (fill).
         * @return the QBrush to used for drawing.
         */
        const QBrush& brush();

        /*!
         * Sets the brush to draw the geometry with (fill).
         * @param brush The QBrush to used for drawing.
         */
        virtual void setBrush(const std::shared_ptr<QBrush>& brush);

        /*!
         * Sets the brush to draw the geometry with (fill).
         * @param brush The QBrush to used for drawing.
         */
        virtual void setBrush(const QBrush& brush);

        /*!
         * Fetches a meta-data value.
         * @param key The meta-data key.
         * @return the meta-data value.
         */
        QVariant& metadata(const std::string& key) const;

        /*!
         * Set a meta-data key/value.
         * @param key The meta-data key.
         * @param value The meta-data value.
         */
        void setMetadata(const std::string& key, const QVariant& value);

        /*!
         * Set the meta-data value to display with the geometry.
         * @param key The meta-data's key for the value to display.
         * @param zoom_minimum The minimum zoom to display the meta-data value at.
         * @param alignment_type The alignment type to use when displaying the meta-data value.
         * @param alignment_offset_px The offset that the meta-data value is displayed from in pixels.
         */
        void setMetadataDisplayed(const std::string& key, const int& zoom_minimum = 10, const AlignmentType& alignment_type = AlignmentType::TopRight, const double& alignment_offset_px = 5.0);

        /*!
         * Calculates the top-left world point in pixels after the alignment type has been applied.
         * @param point_px The world point in pixels to align.
         * @param alignment_type The alignment type of the world point.
         * @param geometry_size_px The geometry object (widget/pixmap) at this zoom level.
         * @return the top-left world point in pixels.
         */
        PointWorldPx calculateTopLeftPoint(const PointWorldPx& point_px, const AlignmentType& alignment_type, const QSizeF& geometry_size_px) const;

        LayerGeometry *layer() const { return mLayer; }

        AncillaryData *ancillaryData() const { return mAncillaryData; }
        void setAncillaryData(AncillaryData *ptr) {
            mAncillaryData = ptr;
        }

        /* "Callback" functions */

        /// @brief Callback function when a geometry is added in a LayerGeometry.
        ///
        /// Classes can use this callback function to record a layer pointer, for example
        /// @arg layer pointer to a layer "owning" the geometry.
        void onAddedToLayer(LayerGeometry *layer) { Q_UNUSED(layer); }

        /// @brief Callback function when a geometry is removed from the owning LayerGeometry.
        ///
        /// Classes can use this callback function to record a layer pointer, for example
        void onRemovedFromLayer() {}

    public:
        /*!
         * Fetches the bounding box (world coordinates).
         * @param controller_zoom The current controller zoom.
         * @return the bounding box.
         */
        virtual RectWorldCoord boundingBox(const int& controller_zoom) const = 0;

        /*!
         * Checks if the geometry touches (intersects) with another geometry.
         * @param geometry The geometry to check against.
         * @param controller_zoom The current controller zoom.
         * @return whether the geometries touch (intersects).
         */
        virtual bool touches(const Geometry* geometry, const int& controller_zoom) const = 0;

        /*!
         * Draws the geometry to a pixmap using the provided painter.
         * @param painter The painter that will draw to the pixmap.
         * @param backbuffer_rect_coord Only draw geometries that are contained in the backbuffer rect (world coordinates).
         * @param controller_zoom The current controller zoom.
         */
        virtual void draw(QPainter& painter, const RectWorldCoord& backbuffer_rect_coord, const int& controller_zoom) = 0;

    signals:
        /*!
         * Signal emitted when a geometry is clicked.
         * @param geometry The clicked Geometry.
         */
        void geometryClicked(const Geometry* geometry) const;

        /*!
         * Signal emitted when a geometry changes its position.
         * @param geometry The geometry that change position.
         */
        void positionChanged(const Geometry* geometry) const;

        /*!
         * Signal emitted when a change has occurred that requires the layer to be redrawn.
         */
        void requestRedraw() const;

    private:
        //! Disable copy constructor.
        Geometry(const Geometry&); /// @todo remove once MSVC supports default/delete syntax.

        //! Disable copy assignment.
        Geometry& operator=(const Geometry&); /// @todo remove once MSVC supports default/delete syntax.

    private:
        /// The geometry type.
        const GeometryType m_geometry_type;

        /// Minimum zoom level to show this geometry.
        int m_zoom_minimum;

        /// Maximum zoom level to show this geometry.
        int m_zoom_maximum;

        /// z-index for rendering order
        int m_z_index;

        /// Whether the geometry is visible.
        bool m_visible;

        /// The pen to use when drawing a geometry.
        std::shared_ptr<QPen> m_pen;

        /// The brush to use when drawing a geometry.
        std::shared_ptr<QBrush> m_brush;

        /// Meta-data storage.
        mutable std::map<std::string, QVariant> m_metadata;

    protected:
        LayerGeometry *mLayer;

        /// The meta-data's key for the value to display.
        std::string m_metadata_displayed_key;

        /// The minimum zoom to display the meta-data value at.
        int m_metadata_displayed_zoom_minimum;

        /// The alignment type to use when displaying the meta-data value.
        AlignmentType m_metadata_displayed_alignment_type;

        /// The offset that the meta-data value is displayed from in pixels.
        double m_metadata_displayed_alignment_offset_px;

        AncillaryData *mAncillaryData;
    };
}
