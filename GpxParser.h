#ifndef GPXPARSER_H
#define GPXPARSER_H

#include "TourData.h"
#define FILTERSIZE 10
#define FILTERGRADE 0
#define FILTERALTIT 1

class GpxParser : public TourData
{
public:
    GpxParser();
    bool loadGpx( QString fileName );

private:
    double filter( double newValue, int channel );
    void filterReset( double initValue, int channel );

    double m_filter[FILTERSIZE][2];
    int m_cnt[2];
};

#endif // GPXPARSER_H
