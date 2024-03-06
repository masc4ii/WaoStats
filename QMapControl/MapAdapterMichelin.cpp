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

#include "MapAdapterMichelin.h"
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

    MapAdapterMichelin::MapAdapterMichelin(QObject* parent)
        : MapAdapterTile(QUrl("http://map1.viamichelin.com/map/mapdirect?map=viamichelin&z=%zoom&x=%x&y=%y&format=png&version=201503191157&layer=background"), supportedProjections(), 0, 17, 0, false, parent)
    {
        MapCopyrightString::instance()->setCopyright( "Michelin, usage restricted" );
    }
}
