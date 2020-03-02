# The QLed custom widget plugin
QLed is a custom widget plugin for Qt designer. 
![QLed example Screenshot](https://raw.githubusercontent.com/wwrx/QLed/master/example/screenshot.png)


## Installation
1. Clone into a working directory
2. Type qmake <qledplugin.pro>
3. Type make
4. Type make install
5. That's all, your Qt custom widget plugin is installed. You can run Qt Designer
   and you will find the plugin icon in Designer left tollbar


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
widget.setColor(QColor(<your-choice>));
```
* Activate the LED by
```cpp
widget.toggleValue();
```
* You can enable clickable mode by
```cpp
widget.setClickable(true);
```
This way you can toggle the LED by clicking on it.

------------------------------------------------------------------------------
The available shapes are:
* Circle
* Square
* Triangle
* Rounded

### See a demo ptoject in the example directory

## Tested Platforms/Versions
This module has been tested with the following configurations
* Qt 5.14
* Qt Creator 4.11


## Copyright
Copyright (C) 2020 by Adam Kisari

github.com/wwrx   or   kisari.net
 
This work is based on original work by P. Sereno (2010)
http://www.sereno-online.com
Artwork based on Jean-Victor Balin's Open Clip Art Library
jean.victor.balin@gmail.com

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License
version 3 as published by the Free Software Foundation
 
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
https://www.gnu.org/licenses/lgpl-3.0.html


