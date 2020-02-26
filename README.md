# The QLed custom widget plugin

[![GitHub version](https://badge.fury.io/gh/qt/qt5.svg)](https://badge.fury.io/gh/qt/qt5)

QLed is a custom widget plugin for Qt designer. 


## Installation
INSTALLING your custom widget plugin
1. Clone into a working directory
2. Type qmake <qledplugin.pro>
3. Type make
4. Type make install
5. That's all, your Qt custom widget plugin is installed. You can run Qt Designer
   and you will find the plugin icon in Designer left tollbar
I hope you will enjoy using the plugin. Good luck!


## Usage
### Qt Creator
* Add the following to your .pro file.
(replace <your-path> with the actual path to the QLed widget files)
```cpp
INCLUDEPATH += <your-path>/QLed
include(<your-path>/QLed/qled.pri)
```
* Add an empty widget to your .ui file in the designer.
* Promote the widget to QLed (use qled.h as the header file)
* Set up the widget using the following
```cpp
widget.setShape(QLed::ledShape::<your-choice>);
widget.setOnColor(QLed::ledColor::<your-choice>);
widget.setOffColor(QLed::ledColor::<your-choice>);
```
* Activate the LED by
```cpp
widget.toggleValue();
```

The available shapes are:
* Circle
* Square
* Triangle
* Rounded

The available colours are:
* Red
* Green
* Yellow
* Grey
* Orange
* Purple
* Blue


## Copyright
---------

Copyright (C) 2020 by Adam Kisari
github.com/wwrx   or   kisari.net
 
This work is based on original work by P. Sereno (2010)
http://www.sereno-online.com
 
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License
version 3 as published by the Free Software Foundation
 
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
https://www.gnu.org/licenses/lgpl-3.0.html


