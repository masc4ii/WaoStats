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

// Local includes.
#include "qmapcontrol_global.h"
#include "MapAdapterTile.h"

namespace qmapcontrol
{
    //! MapAdapter for Mapterhorn height information.
    /*!
     * This is a conveniece class, which extends and configures a MapAdapterTile.
     *
     * @author masc4ii
     */
    class QMAPCONTROL_EXPORT MapAdapterMapterhorn : public MapAdapterTile
    {
        Q_OBJECT
    public:
        //! Constructor.
        /*!
         * This construct a OpenStreetmap MapAdapter.
         * @param parent QObject parent ownership.
         */
        explicit MapAdapterMapterhorn(QObject* parent = 0);

        //! Disable copy constructor.
        ///MapAdapterMapterhorn(const MapAdapterMapterhorn&) = delete; @todo re-add once MSVC supports default/delete syntax.

        //! Disable copy assignment.
        ///MapAdapterMapterhorn& operator=(const MapAdapterMapterhorn&) = delete; @todo re-add once MSVC supports default/delete syntax.

        //! Destructor.
        ~MapAdapterMapterhorn() { } /// = default; @todo re-add once MSVC supports default/delete syntax.

    private:
        //! Disable copy constructor.
        MapAdapterMapterhorn(const MapAdapterMapterhorn&); /// @todo remove once MSVC supports default/delete syntax.

        //! Disable copy assignment.
        MapAdapterMapterhorn& operator=(const MapAdapterMapterhorn&); /// @todo remove once MSVC supports default/delete syntax.
    };
}
