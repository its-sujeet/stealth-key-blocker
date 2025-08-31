# Disable Windows Keys - Simplified Version

A lightweight Windows application that runs silently in the background to block specific keyboard keys.

## Blocked Keys
- Windows keys (left and right)
- Ctrl keys (left and right)
- Alt keys (left and right)
- Escape key
- Delete key
- Insert key
- Alt+Tab combination

## Files Structure
```
app/
├── app.c           # Main application (silent background process)
├── hook.c          # Keyboard hook implementation
├── hook.def        # DLL export definitions
├── shared.h        # Shared definitions
├── stdafx.h        # Standard includes
└── version.h       # Version information

build.bat           # Build script
clean.bat           # Cleanup script
```

## Building
1. Ensure GCC/MinGW is installed and in your PATH
2. Run `build.bat` to compile both the DLL and executable
3. Built files will be in the `build/` directory

## Usage
1. Run `build\disable-windows-keys.exe`
2. The application runs silently in the background (no window)
3. Specified keys will be blocked system-wide
4. To stop: Use Task Manager to kill the `disable-windows-keys.exe` process

## Notes
- Only one instance can run at a time (mutex protection)
- Function keys and Ctrl+Alt+Delete cannot be blocked due to Windows security restrictions
- The application requires administrator privileges for system-wide key blocking
- No GUI - runs completely in the background

## Development
- To make changes: Edit source files and run `build.bat`
- To clean up: Run `clean.bat` to remove unnecessary files
- Simple GCC compilation, no complex build system required
