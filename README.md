# Stealth Key Blocker

A lightweight, silent background utility that blocks common gaming disruption keys on Windows.

## Attribution

This is a fork of the original [disable-windows-keys](https://github.com/bblanchon/disable-windows-keys) project by **bblanchon**. The original project has been enhanced to support additional key blocking and silent background operation.

## Overview

Tired of accidentally hitting Windows, Ctrl, Alt, or other disruptive keys while gaming? This utility runs silently in the background and blocks key combinations that commonly interrupt gaming sessions.

**Key Features:**
- **Silent Operation**: Runs in background with no GUI or notifications
- **Comprehensive Blocking**: Blocks Windows keys, Ctrl, Alt, Esc, Delete, Insert, and Alt+Tab
- **Gaming Focused**: Designed specifically for uninterrupted gaming sessions
- **Lightweight**: Minimal system resource usage
- **No Installation Required**: Portable executable

## Blocked Keys

The application blocks the following keys and combinations:
- **Windows Key** (Left and Right)
- **Ctrl** (Left and Right)
- **Alt** (Left and Right)
- **Escape**
- **Delete**
- **Insert**
- **Alt+Tab** (prevents window switching)

**Note**: Some system keys like Ctrl+Alt+Delete and Function keys cannot be reliably blocked by user-mode applications and remain functional for system security.

## How It Works

This utility uses Windows low-level keyboard hooks to intercept and block specified key presses before they reach the system or other applications. It runs as a silent background process with no visible interface.

## Usage

### Starting the Application
1. Run `disable-windows-keys.exe`
2. The application starts silently in the background
3. No window or system tray icon appears
4. Keys are immediately blocked

### Stopping the Application
Since the application runs silently, you can stop it using:
- **Task Manager**: End the `disable-windows-keys.exe` process
- **Command Line**: `taskkill /f /im disable-windows-keys.exe`

### Checking if Running
Check Task Manager for the `disable-windows-keys.exe` process to verify it's running.

## Building from Source

### Prerequisites
- GCC compiler (MinGW recommended for Windows)
- Windows SDK headers

### Build Instructions
1. Clone or download this repository
2. Run the build script:
   ```batch
   build.bat
   ```
3. The compiled executable will be in the `build/` directory

### Manual Build
```batch
gcc -shared -o build/disable-windows-keys-hook.dll app/hook.c app/hook.def -luser32
gcc -o build/disable-windows-keys.exe app/app.c -L./build -ldisable-windows-keys-hook -luser32
```

## Files Structure

```
├── app/
│   ├── app.c              # Main application logic
│   ├── hook.c             # Keyboard hook implementation
│   ├── hook.def           # DLL export definitions
│   ├── shared.h           # Shared definitions
│   ├── stdafx.h           # Standard headers
│   └── version.h          # Version information
├── build/                 # Compiled binaries
├── build.bat             # Build script
├── clean.bat             # Cleanup script
└── README.md             # This file
```

## System Requirements

- **Operating System**: Windows 7, 8, 10, 11
- **Architecture**: x86/x64
- **Permissions**: Standard user permissions (no admin required)

## Safety and Security

- **Open Source**: Full source code available for inspection
- **No Network Activity**: Application operates entirely offline
- **No Data Collection**: No user data is collected or transmitted
- **Minimal Permissions**: Runs with standard user privileges

## Troubleshooting

**Application won't start:**
- Ensure both `disable-windows-keys.exe` and `disable-windows-keys-hook.dll` are in the same directory
- Check Windows Defender or antivirus hasn't quarantined the files

**Keys still working:**
- Verify the process is running in Task Manager
- Some protected key combinations (like Ctrl+Alt+Delete) cannot be blocked for security reasons

**High CPU usage:**
- This is not expected; if it occurs, terminate the process and rebuild

## Alternative Solutions

If this utility doesn't meet your needs, consider:
- Registry scancode mapping
- Group Policy modifications
- [SharpKeys](https://github.com/randyrants/sharpkeys) for permanent remapping
- [AutoHotkey](https://www.autohotkey.com/) for custom scripting

## License

This project is open source. See LICENSE.txt for details.

## Contributing

Contributions are welcome! Please feel free to submit issues or pull requests.