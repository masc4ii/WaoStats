QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

macx{
    arm64{
        QMAKE_CC = /opt/homebrew/opt/llvm/bin/clang
        QMAKE_CXX = /opt/homebrew/opt/llvm/bin/clang++
        QMAKE_LINK = /opt/homebrew/opt/llvm/bin/clang++
        QMAKE_CFLAGS += -fopenmp -ftree-vectorize
        QMAKE_CXXFLAGS += -fopenmp -std=c++15 -ftree-vectorize
        INCLUDEPATH += -I/opt/homebrew/opt/llvm/include
        LIBS += -L/opt/homebrew/opt/llvm/lib -lomp -L/opt/homebrew/opt/openssl/lib -lssl
        QMAKE_APPLE_DEVICE_ARCHS = arm64
    }
    else: QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.13
}

CONFIG += qwt
include( $${PWD}/qwt-6.2.0/qwtconfig.pri )
#include( $${PWD}/qwt-6.2.0/qwtbuild.pri )
include( $${PWD}/qwt-6.2.0/qwtfunctions.pri )
macx{
    LIBS += -L/usr/local/qwt-6.2.0/lib/ -framework qwt
    INCLUDEPATH += /usr/local/qwt-6.2.0/lib/qwt.framework/Versions/6/Headers
    qwtAddLibrary(/usr/local/qwt-6.2.0/lib/, qwt)
}
win32{
    LIBS += -L$${PWD}/qwt-6.2.0/lib/ -lqwt
    INCLUDEPATH += $${PWD}/qwt-6.2.0/src
}
linux-g++{
    LIBS += -L$${PWD}/qwt-6.2.0/lib/ -lqwt
    INCLUDEPATH += $${PWD}/qwt-6.2.0/src
}

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include( QMapControl/QMapControl.pro )

#dropbox (run qmake and make in dropboxQt/prj/ before!)
INCLUDEPATH += dropboxQt/src
macx:  LIBS += -L$${PWD}/dropboxQt/prj/ -ldropboxQt
win32: LIBS += -L$${PWD}/dropboxQt/prj/release/ -ldropboxQt
linux-g++:  LIBS += -L$${PWD}/dropboxQt/prj/ -ldropboxQt

SOURCES += \
    DropBoxAuthDialog.cpp \
    FitListener.cpp \
    FitSDKRelease_21.101.00/cpp/fit.cpp \
    FitSDKRelease_21.101.00/cpp/fit_accumulated_field.cpp \
    FitSDKRelease_21.101.00/cpp/fit_accumulator.cpp \
    FitSDKRelease_21.101.00/cpp/fit_buffer_encode.cpp \
    FitSDKRelease_21.101.00/cpp/fit_buffered_mesg_broadcaster.cpp \
    FitSDKRelease_21.101.00/cpp/fit_buffered_record_mesg_broadcaster.cpp \
    FitSDKRelease_21.101.00/cpp/fit_crc.cpp \
    FitSDKRelease_21.101.00/cpp/fit_date_time.cpp \
    FitSDKRelease_21.101.00/cpp/fit_decode.cpp \
    FitSDKRelease_21.101.00/cpp/fit_developer_field.cpp \
    FitSDKRelease_21.101.00/cpp/fit_developer_field_definition.cpp \
    FitSDKRelease_21.101.00/cpp/fit_developer_field_description.cpp \
    FitSDKRelease_21.101.00/cpp/fit_encode.cpp \
    FitSDKRelease_21.101.00/cpp/fit_factory.cpp \
    FitSDKRelease_21.101.00/cpp/fit_field.cpp \
    FitSDKRelease_21.101.00/cpp/fit_field_base.cpp \
    FitSDKRelease_21.101.00/cpp/fit_field_definition.cpp \
    FitSDKRelease_21.101.00/cpp/fit_mesg.cpp \
    FitSDKRelease_21.101.00/cpp/fit_mesg_broadcaster.cpp \
    FitSDKRelease_21.101.00/cpp/fit_mesg_definition.cpp \
    FitSDKRelease_21.101.00/cpp/fit_mesg_with_event_broadcaster.cpp \
    FitSDKRelease_21.101.00/cpp/fit_profile.cpp \
    FitSDKRelease_21.101.00/cpp/fit_protocol_validator.cpp \
    FitSDKRelease_21.101.00/cpp/fit_unicode.cpp \
    GpxParser.cpp \
    LineEditEscDelete.cpp \
    OsmWidget.cpp \
    ServiceDialog.cpp \
    ServiceEntryDialog.cpp \
    Splash.cpp \
    TourData.cpp \
    VScrollArea.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    BikeEditingDelegate.h \
    DropBoxAuthDialog.h \
    FitListener.h \
    FitSDKRelease_21.101.00/cpp/fit.hpp \
    FitSDKRelease_21.101.00/cpp/fit_accelerometer_data_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_accelerometer_data_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_accumulated_field.hpp \
    FitSDKRelease_21.101.00/cpp/fit_accumulator.hpp \
    FitSDKRelease_21.101.00/cpp/fit_activity_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_activity_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_ant_channel_id_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_ant_channel_id_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_ant_rx_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_ant_rx_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_ant_tx_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_ant_tx_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_aviation_attitude_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_aviation_attitude_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_barometer_data_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_barometer_data_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_bike_profile_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_bike_profile_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_blood_pressure_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_blood_pressure_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_buffer_encode.hpp \
    FitSDKRelease_21.101.00/cpp/fit_buffered_mesg_broadcaster.hpp \
    FitSDKRelease_21.101.00/cpp/fit_buffered_record_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_buffered_record_mesg_broadcaster.hpp \
    FitSDKRelease_21.101.00/cpp/fit_buffered_record_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_cadence_zone_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_cadence_zone_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_camera_event_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_camera_event_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_capabilities_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_capabilities_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_climb_pro_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_climb_pro_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_config.hpp \
    FitSDKRelease_21.101.00/cpp/fit_connectivity_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_connectivity_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_course_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_course_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_course_point_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_course_point_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_crc.hpp \
    FitSDKRelease_21.101.00/cpp/fit_date_time.hpp \
    FitSDKRelease_21.101.00/cpp/fit_decode.hpp \
    FitSDKRelease_21.101.00/cpp/fit_developer_data_id_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_developer_data_id_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_developer_field.hpp \
    FitSDKRelease_21.101.00/cpp/fit_developer_field_definition.hpp \
    FitSDKRelease_21.101.00/cpp/fit_developer_field_description.hpp \
    FitSDKRelease_21.101.00/cpp/fit_developer_field_description_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_device_aux_battery_info_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_device_aux_battery_info_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_device_info_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_device_info_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_device_settings_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_device_settings_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_dive_alarm_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_dive_alarm_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_dive_gas_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_dive_gas_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_dive_settings_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_dive_settings_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_dive_summary_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_dive_summary_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_encode.hpp \
    FitSDKRelease_21.101.00/cpp/fit_event_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_event_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_exd_data_concept_configuration_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_exd_data_concept_configuration_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_exd_data_field_configuration_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_exd_data_field_configuration_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_exd_screen_configuration_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_exd_screen_configuration_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_exercise_title_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_exercise_title_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_factory.hpp \
    FitSDKRelease_21.101.00/cpp/fit_field.hpp \
    FitSDKRelease_21.101.00/cpp/fit_field_base.hpp \
    FitSDKRelease_21.101.00/cpp/fit_field_capabilities_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_field_capabilities_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_field_definition.hpp \
    FitSDKRelease_21.101.00/cpp/fit_field_description_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_field_description_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_file_capabilities_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_file_capabilities_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_file_creator_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_file_creator_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_file_id_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_file_id_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_goal_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_goal_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_gps_metadata_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_gps_metadata_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_gyroscope_data_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_gyroscope_data_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_hr_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_hr_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_hr_zone_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_hr_zone_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_hrm_profile_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_hrm_profile_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_hrv_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_hrv_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_jump_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_jump_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_lap_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_lap_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_length_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_length_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_magnetometer_data_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_magnetometer_data_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_memo_glob_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_memo_glob_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_mesg_broadcast_plugin.hpp \
    FitSDKRelease_21.101.00/cpp/fit_mesg_broadcaster.hpp \
    FitSDKRelease_21.101.00/cpp/fit_mesg_capabilities_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_mesg_capabilities_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_mesg_definition.hpp \
    FitSDKRelease_21.101.00/cpp/fit_mesg_definition_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_mesg_with_event.hpp \
    FitSDKRelease_21.101.00/cpp/fit_mesg_with_event_broadcaster.hpp \
    FitSDKRelease_21.101.00/cpp/fit_mesg_with_event_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_met_zone_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_met_zone_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_monitoring_info_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_monitoring_info_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_monitoring_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_monitoring_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_nmea_sentence_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_nmea_sentence_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_obdii_data_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_obdii_data_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_ohr_settings_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_ohr_settings_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_one_d_sensor_calibration_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_one_d_sensor_calibration_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_pad_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_pad_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_power_zone_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_power_zone_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_profile.hpp \
    FitSDKRelease_21.101.00/cpp/fit_protocol_validator.hpp \
    FitSDKRelease_21.101.00/cpp/fit_record_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_record_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_runtime_exception.hpp \
    FitSDKRelease_21.101.00/cpp/fit_schedule_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_schedule_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_sdm_profile_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_sdm_profile_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_segment_file_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_segment_file_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_segment_id_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_segment_id_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_segment_lap_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_segment_lap_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_segment_leaderboard_entry_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_segment_leaderboard_entry_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_segment_point_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_segment_point_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_session_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_session_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_set_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_set_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_slave_device_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_slave_device_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_software_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_software_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_speed_zone_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_speed_zone_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_split_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_split_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_sport_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_sport_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_stress_level_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_stress_level_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_three_d_sensor_calibration_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_three_d_sensor_calibration_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_time_in_zone_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_time_in_zone_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_timestamp_correlation_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_timestamp_correlation_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_totals_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_totals_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_training_file_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_training_file_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_unicode.hpp \
    FitSDKRelease_21.101.00/cpp/fit_user_profile_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_user_profile_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_video_clip_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_video_clip_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_video_description_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_video_description_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_video_frame_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_video_frame_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_video_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_video_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_video_title_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_video_title_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_watchface_settings_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_watchface_settings_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_weather_alert_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_weather_alert_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_weather_conditions_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_weather_conditions_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_weight_scale_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_weight_scale_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_workout_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_workout_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_workout_session_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_workout_session_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_workout_step_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_workout_step_mesg_listener.hpp \
    FitSDKRelease_21.101.00/cpp/fit_zones_target_mesg.hpp \
    FitSDKRelease_21.101.00/cpp/fit_zones_target_mesg_listener.hpp \
    Globals.h \
    GpxParser.h \
    LineEditEscDelete.h \
    MainWindow.h \
    OsmWidget.h \
    ServiceDialog.h \
    ServiceEntryDialog.h \
    Splash.h \
    TourData.h \
    VScrollArea.h

FORMS += \
    DropBoxAuthDialog.ui \
    MainWindow.ui \
    ServiceDialog.ui \
    ServiceEntryDialog.ui

INCLUDEPATH += -I FitSDKRelease_21.101.00/cpp/

#Application version
VERSION_MAJOR = 1
VERSION_MINOR = 0
VERSION_PATCH = 0
VERSION_BUILD = 0

#Target version
DEFINES += "VERSION_MAJOR=$$VERSION_MAJOR"\
           "VERSION_MINOR=$$VERSION_MINOR"\
           "VERSION_PATCH=$$VERSION_PATCH"\
           "VERSION_BUILD=$$VERSION_BUILD"
VERSION = $${VERSION_MAJOR}.$${VERSION_MINOR}.$${VERSION_PATCH}.$${VERSION_BUILD}

win32{
    RC_ICONS = WaoStatsLogoMapSmall.ico
    QMAKE_TARGET_COMPANY = masc
    QMAKE_TARGET_DESCRIPTION = "Tool for Wahoo ELEMNT track statistics"
    QMAKE_TARGET_PRODUCT = WaoStats
    RC_CODEPAGE = 1252
}
macx{
    ICON = WaoStatsLogoMapSmall.icns
    QMAKE_INFO_PLIST = Info.plist
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
