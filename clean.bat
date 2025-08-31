@echo off
echo Cleaning up unnecessary files...

:: Remove GUI-related files
if exist "app\mainwindow.c" del "app\mainwindow.c"
if exist "app\mainwindow.h" del "app\mainwindow.h"
if exist "app\resource.rc" del "app\resource.rc"
if exist "app\resource.h" del "app\resource.h"

:: Remove CMake files
if exist "app\CMakeLists.txt" del "app\CMakeLists.txt"
if exist "CMakeLists.txt" del "CMakeLists.txt"

:: Remove setup directory
if exist "setup" rmdir /s /q "setup"

:: Remove assets directory
if exist "assets" rmdir /s /q "assets"

:: Remove old build directories
if exist "build_manual" rmdir /s /q "build_manual"

:: Remove other build-related files
if exist ".clang-format" del ".clang-format"

echo Cleanup completed!
echo.
echo Remaining essential files:
echo - app\app.c (main application)
echo - app\hook.c (keyboard hook)
echo - app\hook.def (DLL exports)
echo - app\shared.h (shared definitions)
echo - app\stdafx.h (standard includes)
echo - app\version.h (version info)
echo - build.bat (build script)
echo.
pause
