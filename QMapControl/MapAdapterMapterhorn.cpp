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

#include "MapAdapterMapterhorn.h"
#include "MapCopyrightString.h"

namespace qmapcontrol
{
    namespace
    {
        /// @todo remove once MSVC supports initializer lists.
        std::set<projection::EPSG> supportedProjections()
        {
            std::set<projection::EPSG> projections;
            projections.insert(projection::EPSG::SphericalMercator);
            return projections;
        }
    }

    MapAdapterMapterhorn::MapAdapterMapterhorn(QObject* parent)
        : MapAdapterTile(QUrl("https://tiles.mapterhorn.com/%zoom/%x/%y.webp"), supportedProjections(), 0, 17, 0, false, parent) /// @todo remove once MSVC supports initializer lists.
    {
        MapCopyrightString::instance()->setCopyright( "Mapterhorn" );
    }
}
