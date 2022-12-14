# WaoStats

<img width="128" alt="icon" src="https://user-images.githubusercontent.com/30245296/205703174-b3d32a43-6e8e-415d-a7e5-00cdec2a0b6c.png">

A desktop application to analyse and archive your **Wahoo ELEMNT** bike computer tracks. It runs on **macOS** and **Windows**, maybe also **Linux**.

<img width="1000" alt="waostats" src="https://user-images.githubusercontent.com/30245296/195997239-19587c70-079c-4a51-8231-fe0a10e137cb.png">

## Main features are:
- load all your Wahoo FIT files into the application
- view the statistics (entire track and lap/section) from your FIT files
- view your Wahoo computer firmware versions, used sensors and their battery status (when track ended)
- plot the recorded values (altitude, speed, cadence, temperature, grade, heartrate, power, battery, calories, L/R balance, gears, gear ratio) from your FIT files, over time or over distance
- link your tracks to your used devices (bikes) and see total kilometers per device
- dropbox sync your FIT files
- display your track on 11 different maps (google, openstreetmap, bing and more)

## Used Libraries
- dropboxQt, under [MIT](https://github.com/masc4ii/WaoStats/blob/main/dropboxQt/LICENSE)
- Qwt 6.2.0, under [Qwt License](https://qwt.sourceforge.io/qwtlicense.html), download code from official webpage
- QMapControl, under [LGPL 3.0](https://github.com/masc4ii/WaoStats/blob/main/QMapControl/COPYING.LESSER)
- FitSDKRelease_21.94.00, download code from Garmin official SDK webpage
- App Icon by [71M](https://zez.am/71m)

## Compile
- Download Qwt 6.2.0 and copy archive content into qwt-6.2.0 folder, compile and install as usual
- Download FitSDKRelease_21.94.00 and copy archive content into FitSDKRelease_21.94.00 folder
- Compile dropboxQt, as described in subfolder dropboxQt. You should get "WaoStats/dropboxQt/prj/libdropboxQt.a"
- Open WaoStats.pro into QtCreator, compile with **Qt5.15.2 and Clang(macOS) or minGW(Windows)**
- On Windows, install OpenSSL and copy library files to application folder

## Application - First Start
- Open application.
- Choose from WaoStats menu: Archive - Set Archive Path.
- Create / select a path of your choice.
- In this path, create subfolders for your bikes (or choose from WaoStats menu: Archive - Add New Bike).
- Put your fit files into these subfolders.
- Choose from WaoStats menu: Archive - Scan Tour Folder.
<img width="450" alt="archive" src="https://user-images.githubusercontent.com/30245296/206466669-40a9026a-cb13-4f36-8610-01840d039c42.png">

## Dropbox Setup
- Get an API app key by registering with Dropbox: https://dropbox.com/developers/apps
- Click "Create app", give it reading permission to your "Apps/WahooFitness" folder.
- Enter app key and app secret to WaoStats dropbox menu.
- Click "Get Token", follow the dropbox pages.
- Copy the token from dropbox page into WaoStats menu.
- WaoStats now is allowed to read your fit files (once). Another reading process needs a new token with same keys.
- Find downloaded fit tracks in archive folder / WaoStats left list "New"
