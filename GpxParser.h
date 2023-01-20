#ifndef GPXPARSER_H
#define GPXPARSER_H

#include "TourData.h"

class GpxParser : public TourData
{
public:
    GpxParser();
    bool loadGpx( QString fileName );

private:
    double getDistanceFromLatLonInKm( double lat1, double lon1, double lat2, double lon2);
    double deg2rad( double deg );
    double gradeFilter( double newValue );
};

#endif // GPXPARSER_H
