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
    //! MapAdapter for ThunderforestCycle.
    /*!
     * This is a conveniece class, which extends and configures a MapAdapterTile.
     *
     * @author Kai Winter <kaiwinter@gmx.de>
     * @author Chris Stylianou <chris5287@gmail.com>
     * @author Andrii Shelestov <streamx3@gmail.com>
     * @author masc4ii
     */
    class QMAPCONTROL_EXPORT MapAdapterThunderCycle : public MapAdapterTile
    {
        Q_OBJECT
    public:
        /// Different Google layer types available.
        enum class ThunderforestLayerType
        {
            /// cycle layer.
            CYCLE,
            /// landscape layer.
            LANDSCAPE
        };

    public:
        //! Constructor.
        /*!
         * This construct a Thunderforest Cycle MapAdapter.
         * @param parent QObject parent ownership.
         */
        explicit MapAdapterThunderCycle(const ThunderforestLayerType &layer_type = ThunderforestLayerType::CYCLE, QObject* parent = 0);

        //! Destructor.
        ~MapAdapterThunderCycle() { } /// = default; @todo re-add once MSVC supports default/delete syntax.

        /*!
         * Convert the enum to a string representation.
         * @param layer_type The layer type to convert.
         * @return the 1-character representation.
         */
        QString layerTypeToString(const MapAdapterThunderCycle::ThunderforestLayerType& layer_type);

    private:
        //! Disable copy constructor.
        MapAdapterThunderCycle(const MapAdapterThunderCycle&); /// @todo remove once MSVC supports default/delete syntax.

        //! Disable copy assignment.
        MapAdapterThunderCycle& operator=(const MapAdapterThunderCycle&); /// @todo remove once MSVC supports default/delete syntax.
    };
}
