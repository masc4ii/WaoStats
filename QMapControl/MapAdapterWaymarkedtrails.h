/*
*
* This file is part of QMapControl,
* an open-source cross-platform map widget
*
* Copyright (C) 2022 masc4ii
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
* Program URL   : http://qmapcontrol.sourceforge.net/
*
*/

#pragma once

// Local includes.
#include "qmapcontrol_global.h"
#include "MapAdapterTile.h"

namespace qmapcontrol
{
    //! MapAdapter for Waymarkedtrails.
    /*!
     * This is a conveniece class, which extends and configures a MapAdapterTile.
     *
     * @author masc4ii
     */
    class QMAPCONTROL_EXPORT MapAdapterWaymarkedtrails : public MapAdapterTile
    {
        Q_OBJECT
    public:
        /// Different Waymarkedtrails layer types available.
        enum class WaymarkedtrailsLayerType
        {
            /// cycling layer.
            CYCLING,
            /// mtb layer.
            MTB,
            /// hiking layer
            HIKING
        };

    public:
        //! Constructor.
        /*!
         * This construct a Waymarkedtrails MapAdapter.
         * @param parent QObject parent ownership.
         */
        explicit MapAdapterWaymarkedtrails(const WaymarkedtrailsLayerType &layer_type = WaymarkedtrailsLayerType::CYCLING, QObject* parent = 0);

        //! Destructor.
        ~MapAdapterWaymarkedtrails() { } /// = default; @todo re-add once MSVC supports default/delete syntax.

        /*!
         * Convert the enum to a string representation.
         * @param layer_type The layer type to convert.
         * @return the 1-character representation.
         */
        QString layerTypeToString(const MapAdapterWaymarkedtrails::WaymarkedtrailsLayerType& layer_type);

    private:
        //! Disable copy constructor.
        MapAdapterWaymarkedtrails(const MapAdapterWaymarkedtrails&); /// @todo remove once MSVC supports default/delete syntax.

        //! Disable copy assignment.
        MapAdapterWaymarkedtrails& operator=(const MapAdapterWaymarkedtrails&); /// @todo remove once MSVC supports default/delete syntax.
    };
}
