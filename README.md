# WaoStats
A desktop application to analyse and archive your Wahoo ELEMNT bike computer tracks.

<img width="1000" alt="waostats" src="https://user-images.githubusercontent.com/30245296/195997239-19587c70-079c-4a51-8231-fe0a10e137cb.png">

## Main features are:
- load all your Wahoo FIT files into the application
- view the statistics from your FIT files
- view your Wahoo computer firmware versions, used sensors and their battery status (when track ended)
- plot the recorded values (altitude, speed, cadence, temperature, grade) from your FIT files
- link your tracks to your used devices (bikes) and see total kilometers per device
- dropbox sync your FIT files
- display your track on 11 different maps (google, openstreetmap, bing and more)

## Used Libraries
- dropboxQt, under [MIT](https://github.com/masc4ii/WaoStats/blob/main/dropboxQt/LICENSE)
- Qwt 6.2.0, under [Qwt License](https://qwt.sourceforge.io/qwtlicense.html), download code from official webpage
- QMapControl, under [LGPL 3.0](https://github.com/masc4ii/WaoStats/blob/main/QMapControl/COPYING.LESSER)
- FitSDKRelease_21.94.00, download code from Garmin official SDK webpage

## Compile
- Download Qwt 6.2.0 and copy archive content into qwt-6.2.0 folder, compile and install as usual
- Download FitSDKRelease_21.94.00 and copy archive content into FitSDKRelease_21.94.00 folder
- Compile dropboxQt, as described in subfolder dropboxQt. You should get "WaoStats/dropboxQt/prj/libdropboxQt.a"
- Open WaoStats.pro into QtCreator, compile with Qt5.15.3 and Clang(macOS) or minGW(Windows)
