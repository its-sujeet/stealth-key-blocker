// Disable Windows Keys
// https://bblanchon.github.io/disable-windows-keys
// Copyright (C) 2020  Benoit Blanchon

#include "shared.h"
#include "stdafx.h"

LRESULT CALLBACK HookProc(int nCode, WPARAM wParam, LPARAM lParam) {
  if (nCode == HC_ACTION) {
    KBDLLHOOKSTRUCT* pKbd = (KBDLLHOOKSTRUCT*)lParam;
    DWORD vkCode = pKbd->vkCode;
    
    // Block Windows keys
    if (vkCode == VK_LWIN || vkCode == VK_RWIN) {
      return 1; // Block the key
    }
    
    // Block Ctrl keys
    if (vkCode == VK_LCONTROL || vkCode == VK_RCONTROL) {
      return 1; // Block the key
    }
    
    // Block Alt keys
    if (vkCode == VK_LMENU || vkCode == VK_RMENU) {
      return 1; // Block the key
    }
    
    // Block Escape key
    if (vkCode == VK_ESCAPE) {
      return 1; // Block the key
    }
    
    // Block Delete key
    if (vkCode == VK_DELETE) {
      return 1; // Block the key
    }
    
    // Block Insert key
    if (vkCode == VK_INSERT) {
      return 1; // Block the key
    }
    
    // Block Tab when Alt is pressed (Alt+Tab)
    if (vkCode == VK_TAB && (GetAsyncKeyState(VK_MENU) & 0x8000)) {
      return 1; // Block the key
    }
  }
  
  return CallNextHookEx(NULL, nCode, wParam, lParam);
}