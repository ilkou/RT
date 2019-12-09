# RT

an infrastructure capable of supporting different features and obtain sublime computer-generated images using the RAYTRACING method.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

#### Mac OS
```
Nothing :)
```

#### Windows

* terminal of ubuntu or other linux distributions (windows store)
#### to run graphical Linux programs on your windows 10 desktop you need a GUI server, such as X11. Such doesn’t not exist for Windows, but there are alternatives, one of which is Xming, which can be downloaded free of charge, from SourceForge : https://sourceforge.net/projects/xming/ (set private when ask) then enable bash to use xming which can be done by typing the following line
```
echo "export DISPLAY=:0" >> ~/.bashrc
```
* install SDL packages:
```
apt-get install libsdl-image1.2 libsdl-image1.2-dev libsdl-ttf2.0-0 libsdl-ttf2.0-dev libsdl-mixer1.2 libsdl-mixer1.2-dev
```
#### Linux

* update and upgrade ur system:
```
apt-get update
apt-get upgrade
```
* install gcc and make
* install the following packages:
```
apt-get install libx11-dev
apt-get install libxext-dev
```

### Installing
```
- default window size:
  make
- for a specific window size:
  make WIDTH=1500
```

## Run the program

### Language: C

### Libraries: SDL, miniLibX, pthread

### Features implemented:
```
Voronoi noise, Perlin noise, UV mapping, Reflection, Antialiasing, Motion blur, Multi thread computing, slice different objects following its own axis, Point light, Parallel light, Soft shadow
```

### Objects:
```
The Moebius ribbon, perforated cube, torus, paraboloid, hyperboloid, cube, cone, cylinder, sphere, plane, triangle..
```

### Resources
* [Ray tracing in One Weekend](https://www.realtimerendering.com/raytracing/Ray%20Tracing%20in%20a%20Weekend.pdf) - Positionable camera
* [Phong](https://en.wikipedia.org/wiki/Phong_reflection_model) - Phong reflection model
* [Moebius](https://www.mathcurve.com/surfaces/mobiussurface/mobiussurface.shtml) - The Moebius ribbon
* [Voronoi noise](https://www.ronja-tutorials.com/2018/09/29/voronoi-noise.html) - a noise based on cells
* [Perlin noise](https://www.realtimerendering.com/raytracing/Ray%20Tracing_%20The%20Next%20Week.pdf) - a repeatable noise

## Video
* [Youtube link](https://www.youtube.com/watch?v=Dg9k2Idyrx0)

## Pics 
![alt text](https://github.com/ilkou/rt/blob/master/ScreenShot/13377.png "1337 logo")
![alt text](https://github.com/ilkou/rt/blob/master/ScreenShot/all_limited.png "limited objects")
![alt text](https://github.com/ilkou/rt/blob/master/ScreenShot/flashlight.png "flashlight-spotlight")
![alt text](https://github.com/ilkou/rt/blob/master/ScreenShot/42.png "reflection of earth on perlin")
![alt text](https://github.com/ilkou/rt/blob/master/ScreenShot/multi-objet.png "uv mapping")
![alt text](https://github.com/ilkou/rt/blob/master/ScreenShot/multi-objet-focus.png "focus")
![alt text](https://github.com/ilkou/rt/blob/master/ScreenShot/multi-objet-cartoon.png "cartoon-filter")
![alt text](https://github.com/ilkou/rt/blob/master/ScreenShot/android.png "android")
![alt text](https://github.com/ilkou/rt/blob/master/ScreenShot/table.png "table")
![alt text](https://github.com/ilkou/rt/blob/master/ScreenShot/space3jpg.png "space")
![alt text](https://github.com/ilkou/rt/blob/master/ScreenShot/sphere-no-soft-shadow.png "normal shadow")
![alt text](https://github.com/ilkou/rt/blob/master/ScreenShot/sphere-soft-shadow.png "softshadow")
![alt text](https://github.com/ilkou/rt/blob/master/ScreenShot/demo1.png "limited cone + perlin")
![alt text](https://github.com/ilkou/rt/blob/master/ScreenShot/moebius.png "moebius")
![alt text](https://github.com/ilkou/rt/blob/master/ScreenShot/all.png "different objects")
![alt text](https://github.com/ilkou/rt/blob/master/ScreenShot/all2.png "different objects")
