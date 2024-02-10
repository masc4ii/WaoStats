# WaoStats

<img width="128" alt="icon" src="https://user-images.githubusercontent.com/30245296/205703174-b3d32a43-6e8e-415d-a7e5-00cdec2a0b6c.png">

[![macOS](https://img.shields.io/badge/mac%20os-000000?style=flat&logo=apple&logoColor=white)](https://www.apple.com/macos)
[![Windows](https://img.shields.io/badge/Windows-0078D6?style=flat&logo=windows&logoColor=white)](https://www.microsoft.com/windows)
[![wahooELEMNT](https://img.shields.io/badge/wahoo-ELEMNT-red)](https://de-eu.wahoofitness.com/devices/bike-computers)
[![Qt&5](https://img.shields.io/badge/Qt-5-brightgreen)](https://doc.qt.io/qt-5/)
[![FitSDK](https://img.shields.io/badge/FitSDKRelease-21.105.00-brightgreen)](https://developer.garmin.com/fit/download/)
[![dropboxQt](https://img.shields.io/badge/dropboxQt-yellow)](https://github.com/osoftteam/dropboxQt)
[![QMapControl](https://img.shields.io/badge/QMapControl-yellow)](https://github.com/TheDZhon/QMapControl)
[![QCustomPlot](https://img.shields.io/badge/QCustomPlot-yellow)](https://www.qcustomplot.com)

[![Commit Activity](https://img.shields.io/github/commit-activity/m/masc4ii/WaoStats)](https://github.com/masc4ii/WaoStats/pulse)
[![Last Commit](https://img.shields.io/github/last-commit/masc4ii/WaoStats)](https://github.com/masc4ii/WaoStats/pulse)
[![Contributors](https://img.shields.io/github/contributors/masc4ii/WaoStats)](https://github.com/masc4ii/WaoStats/graphs/contributors)
[![Open Issues](https://img.shields.io/github/issues/masc4ii/WaoStats)](https://github.com/masc4ii/WaoStats/issues)
[![Closed Issues](https://img.shields.io/github/issues-closed/masc4ii/WaoStats)](https://github.com/masc4ii/WaoStats/issues?q=is%3Aissue+is%3Aclosed)

A desktop application to analyse and archive your **Wahoo ELEMNT** bike computer tracks. It runs on **macOS**, **Windows** and **Linux**.

<img width="1000" alt="waostats" src="https://github.com/masc4ii/WaoStats/assets/30245296/6cfd02fc-df87-4b66-8074-3f30f2dde2bd">

## Main features are:
- load all your Wahoo FIT files into the application
- view the statistics (entire track and lap/section) from your FIT files
- view your Wahoo computer firmware versions, used sensors and their battery status (when track ended)
- plot the recorded values (altitude, speed, cadence, temperature, grade, heartrate, power, battery, calories, L/R balance, gears, gear ratio, gps accuracy) from your FIT files, over time or over distance
- link your tracks to your used devices (bikes) and see total kilometers per device
- dropbox sync your FIT files
- ADB (USB) sync your FIT files directly from your Wahoo bike computer
- display your track on 16 different maps (google, openstreetmap, bing and more)
- load GPX tracks into the application with reduced statistics (compared to FIT)
- log service activities and get service reminders

## Used Libraries
- dropboxQt, under [MIT](https://github.com/masc4ii/WaoStats/blob/main/dropboxQt/LICENSE)
- QCustomPlot, under [GPL 3.0](https://github.com/masc4ii/WaoStats/blob/main/qcustomplot/GPL.txt)
- QMapControl, under [LGPL 3.0](https://github.com/masc4ii/WaoStats/blob/main/QMapControl/COPYING.LESSER)
- FitSDKRelease_21.105.00, download code from Garmin official SDK webpage
- App Icon by [71M](https://zez.am/71m)

## Download
- Download [here](https://github.com/masc4ii/WaoStats/releases)
- Currently supported OS: macOS 10.13.6 and later, Windows 8 and later, Ubuntu 20.04 and later

## Compile
- Download FitSDKRelease_21.101.00 and copy archive content into FitSDKRelease_21.101.00 folder (when using fit C++ parser only - by default this step not needed)
- Compile dropboxQt, as described in subfolder dropboxQt. You should get "WaoStats/dropboxQt/prj/libdropboxQt.a"
- Open WaoStats.pro into QtCreator, compile with **Qt5.15.2 and Clang(macOS) or minGW(Windows)**
- On Windows, install OpenSSL and copy library files to application folder

Compiling on Ubuntu: [howto](https://github.com/masc4ii/WaoStats/blob/main/docs/WaoStats-Ubuntu.md) (thanks to [Intyre](https://gist.github.com/Intyre))

## Application - First Start
- Open application.
- Create / select a path of your choice, which shall contain your track files (fit/gpx).
- In this path, create subfolders for your bikes (or choose from WaoStats menu: Archive - Add New Bike).
- Put your track files (fit/gpx) into these subfolders.
- Choose from WaoStats menu: Archive - Scan Tour Folder.
<img width="450" alt="archive" src="https://user-images.githubusercontent.com/30245296/206466669-40a9026a-cb13-4f36-8610-01840d039c42.png">

## Dropbox Sync
### Tutorial video
[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/EHSu15v0cd0/0.jpg)](https://www.youtube.com/watch?v=EHSu15v0cd0)
### Setup (do this before first sync)
- Get an API app key by registering with Dropbox: https://dropbox.com/developers/apps
- Click "Create app", give it reading permission to your "Apps/WahooFitness" folder. (Probably just option "Full Dropbox" can do this.)
- On next page ("Permissions"), check "files.content.read" and "profile". Click "Submit".
- Find your app key and app secret on page "Settings".
### Sync
- Enter app key and app secret to WaoStats dropbox menu.
- Click "Get Token", follow the dropbox pages.
- Copy the token from dropbox page into WaoStats menu.
- WaoStats now is allowed to read your fit files (once). Another reading process needs a new token with same keys.
- Find downloaded fit tracks in archive folder / WaoStats left list "New"

## ADB Sync
- Connect Wahoo device to your computer.
- Open in WaoStats Archive -> ADB Sync, click Scan. The Wahoo device should be shown "unauthorized".
- Disconnect Wahoo device to your computer.
- Start debug mode for Wahoo device. (Press Up+Down+Power at the same time. Do this in Wahoos Pan & Zoom mode, because here menu options stay untouched.)
- Connect Wahoo device to your computer.
- Open in WaoStats Archive -> ADB Sync, click Scan. The Wahoo device should be shown with its name.
- Choose your device and click select.
- Find downloaded fit tracks in archive folder / WaoStats left list "New"

## Plot
- Wheel: zoom
- Left drag: move
- Right click: select between curves
