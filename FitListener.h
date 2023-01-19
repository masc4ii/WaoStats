#ifndef FITLISTENER_H
#define FITLISTENER_H

#include "fit_decode.hpp"
#include "fit_mesg_broadcaster.hpp"
#include "fit_developer_field_description.hpp"

#include <fstream>
#include <iostream>
#include <QString>
#include <QVector>
#include "TourData.h"

class FitListener
        : public fit::FileIdMesgListener
        , public fit::MesgListener
        , public fit::DeveloperFieldDescriptionListener
        , public TourData
{
public:
    FitListener();

    static void PrintValues(const fit::FieldBase& field);
    void OnMesg(fit::Mesg& mesg);
    void OnMesg(fit::FileIdMesg& mesg);
    void OnDeveloperFieldDescription( const fit::DeveloperFieldDescription& desc ) override { return; }
};

#endif // FITLISTENER_H
