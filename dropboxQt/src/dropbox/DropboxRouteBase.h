#pragma once

#include <functional>

namespace dropboxQt{

    class Endpoint;

    class DropboxRouteBase
    {        
    public:
        DropboxRouteBase(Endpoint* ep):m_end_point(ep){}

    protected:
        Endpoint* m_end_point;
    };

}
