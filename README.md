![Relooker](http://wakowakowako.com/mixbo/header3.png)


### Status
[![Version](https://img.shields.io/badge/Version-v0.4.1-brightgreen.svg)](https://github.com/Mixbo/relooker/releases/tag/v0.4.1)
[![Build](https://travis-ci.org/Mixbo/relooker.svg?branch=master)](https://travis-ci.org/Mixbo/relooker/builds)

## Intro


RElooker is a simple Reverse Engineering software designed to visualize binary information with colorful representations and stats. It is 100% cross platform (even if the formatting sometimes sucks).

Basic editing will also be possible sooner or later.
Current [release](https://github.com/Mixbo/relooker/releases)

## Which files can I analyze?
Any. Most features are structure independant and interpret the actual content of the file instead of relying on headers and/or prior knowledge. What you see is what you get.

![Screenshot](http://wakowakowako.com/mixbo/5_screen.png)

## Install
#### Install on Linux and Mac OS X
```
$ ./kompile 
```
A few releases were published with a compiled executable.
## Features
#### Currently Working
* 2D Visualization
  * Value range (Null,FF,Low,High,Ascii)
  * Entropy Viewer
* Hex Viewer
* String Highlight
* Graphic Stats (Pie Charts!)

#### ToDo
* Call Structure Viewer
* Media listing
* 3D Viewer (!)
* Create Editors
  * Hex Editor
  * Strings Editor
  * Ressources Editor
  * Disassembly Editor (!)

Visit [the wiki](https://github.com/Mixbo/relooker/wiki) for more informations on which features are being developped.
If you want the ~~latest~~ **unstable** version, consider cloning the [dev branch](https://github.com/Mixbo/relooker/tree/dev).
