#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <math.h>

class HelperFunctions
{
public:
    double getDistanceFromLatLonInKm( double lat1, double lon1, double lat2, double lon2 )
    {
        double R = 6371.0; // Radius of the earth in km
        double dLat = fabs( deg2rad(lat2-lat1) );  // deg2rad below
        double dLon = fabs( deg2rad(lon2-lon1) );
        double a =
            sin( dLat / 2.0 ) * sin( dLat / 2.0 ) +
            cos( deg2rad( lat1 ) ) * cos( deg2rad( lat2 ) ) *
                sin( dLon / 2.0 ) * sin( dLon / 2.0 );
        double c = 2.0 * atan2( sqrt( a ), sqrt( 1.0 - a ));
        double d = R * c; // Distance in km
        return d;
    }

private:
    double deg2rad( double deg )
    {
        return deg * ( M_PI / 180.0 );
    }
};

#endif // HELPERFUNCTIONS_H
