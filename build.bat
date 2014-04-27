@echo off
mkdir build
xcopy /E components build
cd build
qmake
mingw32-make