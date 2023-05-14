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

#include "MapAdapterSigma.h"
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

    /// http://tiles1.sigma-dc-control.com/layer5/{z}/{x}/{y}.png
    MapAdapterSigma::MapAdapterSigma(const MapAdapterSigma::MapAdapterSigmaType& layer_type,
                                     QObject* parent)
        : MapAdapterTile(QUrl("http://tiles1.sigma-dc-control.com/"+layerTypeToString(layer_type)+"/%zoom/%x/%y.png"),
                         supportedProjections(), 0, 17, 0, false, parent) /// @todo remove once MSVC supports initializer lists.
    {
        MapCopyrightString::instance()->setCopyright( "OpenStreetMap contributors" );
    }

    QString MapAdapterSigma::layerTypeToString(const MapAdapterSigmaType &layer_type)
    {
        switch (layer_type)
        {
        case MapAdapterSigmaType::CYCLE:
            return "layer8";
        case MapAdapterSigmaType::MAPS:
            return "layer1";
        case MapAdapterSigmaType::TOPO:
        default:
            return "layer5";
        }
    }
}
