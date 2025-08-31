// Disable Windows Keys
// https://bblanchon.github.io/disable-windows-keys
// Copyright (C) 2020  Benoit Blanchon

#include "shared.h"
#include "stdafx.h"

LPCTSTR hookDllName = TEXT("disable-windows-keys-hook.dll");
LPCSTR hookProcName = "HookProc";
LPCTSTR szSingleInstanceMutexName = TEXT("{20CDC7AA-BCF7-4C09-B639-258CC68AC68D}");

int WINAPI _tWinMain(__in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance,
                     __in LPTSTR lpCmdLine, __in int nShowCmd) {

  UNREFERENCED_PARAMETER(hPrevInstance);
  UNREFERENCED_PARAMETER(nShowCmd);

  // If an instance is already running, exit silently
  CreateMutex(NULL, TRUE, szSingleInstanceMutexName);
  if (GetLastError() == ERROR_ALREADY_EXISTS) {
    return 0;
  }

  // Get language from the command line
  LANGID langid = (LANGID)_tcstoul(lpCmdLine, NULL, 16);
  if (langid) SetThreadUILanguage(langid);

  // Load hook DLL
  HMODULE hdll = LoadLibrary(hookDllName);
  if (hdll == NULL) {
    // Silent failure - no GUI error messages
    return 1;
  }

  // Get the Hook procedure
  HOOKPROC hookProc = (HOOKPROC)GetProcAddress(hdll, hookProcName);
  if (hookProc == NULL) {
    // Silent failure - no GUI error messages
    return 1;
  }

  // Install the hook
  HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, hookProc, hdll, 0);
  if (hook == NULL) {
    // Silent failure - no GUI error messages
    return 1;
  }

  // No GUI window creation - just run the message loop silently
  MSG msg;
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  UnhookWindowsHookEx(hook);

  return 0;
}
