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

// Local includes.
#include "qmapcontrol_global.h"
#include "MapAdapterTile.h"

namespace qmapcontrol
{
    //! MapAdapter for Esri.
    /*!
     * This is a conveniece class, which extends and configures a MapAdapterTile.
     *
     * @author Kai Winter <kaiwinter@gmx.de>
     * @author Chris Stylianou <chris5287@gmail.com>
     * @author Andrii Shelestov <streamx3@gmail.com>
     */
    class QMAPCONTROL_EXPORT MapAdapterEsri : public MapAdapterTile
    {
        Q_OBJECT
    public:
        /// Different Esri layer types available.
        enum class MapAdapterEsriType
        {
            /// topo layer.
            TOPO,
            /// satellite map layer.
            IMAGERY
        };

        //! Constructor.
        /*!
         * This construct a Esri MapAdapter.
         * @param parent QObject parent ownership.
         */
        explicit MapAdapterEsri(const MapAdapterEsriType &layer_type = MapAdapterEsriType::TOPO, QObject* parent = 0);

        //! Destructor.
        ~MapAdapterEsri() { } /// = default; @todo re-add once MSVC supports default/delete syntax.

        /*!
         * Convert the enum to a string representation.
         * @param layer_type The layer type to convert.
         * @return the 1-character representation.
         */
        QString layerTypeToString(const MapAdapterEsri::MapAdapterEsriType& layer_type);

    private:
        //! Disable copy constructor.
        MapAdapterEsri(const MapAdapterEsri&); /// @todo remove once MSVC supports default/delete syntax.

        //! Disable copy assignment.
        MapAdapterEsri& operator=(const MapAdapterEsri&); /// @todo remove once MSVC supports default/delete syntax.
    };
}
