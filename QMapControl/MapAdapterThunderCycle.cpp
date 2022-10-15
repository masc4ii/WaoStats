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

#include "MapAdapterThunderCycle.h"

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

    /// from OSM wiki: http://[abc].tile.thunderforest.com/cycle/zoom/x/y.png
    MapAdapterThunderCycle::MapAdapterThunderCycle( const MapAdapterThunderCycle::ThunderforestLayerType& layer_type,
                                                    QObject* parent)
        : MapAdapterTile(QUrl("http://a.tile.thunderforest.com/"+layerTypeToString(layer_type)+"/%zoom/%x/%y.png"),
                         supportedProjections(), 0, 17, 0, false, parent) /// @todo remove once MSVC supports initializer lists.
    {

    }

    QString MapAdapterThunderCycle::layerTypeToString(const ThunderforestLayerType &layer_type)
    {
        switch (layer_type)
        {
            case ThunderforestLayerType::CYCLE:
                return "cycle";
            case ThunderforestLayerType::LANDSCAPE:
            default:
                return "landscape";
        }
    }
}
