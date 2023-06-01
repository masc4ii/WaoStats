#ifndef FITPARSER_H
#define FITPARSER_H

#include "TourData.h"

class FitParser : public TourData
{
public:
    FitParser();
    bool loadFit( QString fileName );
};

#endif // FITPARSER_H
