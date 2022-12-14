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

#include "MapAdapterOCM.h"
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

    /// from OSM wiki: https://[a|b|c].tile-cyclosm.openstreetmap.fr/[cyclosm|cyclosm-lite]/{z}/{x}/{y}.png
    MapAdapterOCM::MapAdapterOCM(QObject* parent)
        : MapAdapterTile(QUrl("https://a.tile-cyclosm.openstreetmap.fr/cyclosm/%zoom/%x/%y.png"),
                         supportedProjections(), 0, 17, 0, false, parent) /// @todo remove once MSVC supports initializer lists.
    {
        MapCopyrightString::instance()->setCopyright( "CyclOSM | Map data © OpenStreetMap contributors" );
    }
}
