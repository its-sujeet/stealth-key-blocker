@echo off
echo Building disable-windows-keys...

:: Create build directory if it doesn't exist
if not exist "build" mkdir build

:: Change to app directory
cd app

:: Build the hook DLL
echo Building hook DLL...
gcc -shared -o ..\build\disable-windows-keys-hook.dll hook.c hook.def -luser32 -lkernel32 -DUNICODE -D_UNICODE -municode

if %errorlevel% neq 0 (
    echo Error: Hook DLL compilation failed!
    pause
    exit /b 1
)

:: Build the main application
echo Building main application...
gcc -o ..\build\disable-windows-keys.exe app.c -luser32 -lkernel32 -DUNICODE -D_UNICODE -municode -mwindows

if %errorlevel% neq 0 (
    echo Error: Main application compilation failed!
    pause
    exit /b 1
)

:: Return to root directory
cd ..

echo Build completed successfully!
echo Files created in 'build' directory:
echo - disable-windows-keys.exe
echo - disable-windows-keys-hook.dll
echo.
echo To run: build\disable-windows-keys.exe
echo To stop: Use Task Manager to kill the process
pause