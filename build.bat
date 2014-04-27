@echo off
mkdir build
xcopy /E components build
cd build
qmake
mingw32-make

cd components_test\release
components_test.exe
if errorlevel 1 (
	cd ..\..\..\
	echo Tests problem !
	rmdir /s/q build
	exit /b %errorlevel%
)
cd ..\..\..\
copy build\components_src\release\components_src.exe
rmdir /s/q build