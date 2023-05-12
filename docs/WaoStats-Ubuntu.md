# Install Ubuntu packages
```
apt-get install --no-install-recommends \
	make \
	g++ \
	qt5-qmake \
	qtbase5-dev \
	libqt5opengl5-dev \
	libqt5designer5 \
	libqt5svg5-dev
```

## Clone the repo
```
git clone http://github.com/masc4ii/WaoStats
```

## FitSDKRelease:
- [FitSDKRelease_21.105.00.zip](https://developer.garmin.com/downloads/fit/sdk/FitSDKRelease_21.105.00.zip)
```
$ unzip -d FitSDKRelease_21.105.00 FitSDKRelease_21.105.00.zip
```

## qwt-6.2.0
- [qwt-6.2.0.zip](https://sourceforge.net/projects/qwt/files/qwt/6.2.0/qwt-6.2.0.zip/download)
```
$ unzip qwt-6.2.0.zip
$ cd qwt-6.2.0
$ qmake && make && make install
```

## dropboxQt
```
$ cd dropboxQt/prj
$ qmake && make
```

## WaoStats 
```
$ mkdir build
$ cd build
$ qmake .. && make
```
