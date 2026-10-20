#pragma once
#include <WinUser.h>
#include <wtypes.h>

HWND heditControl;

#define OnMenuClicked 1
#define OnExitSoftware 4
#define OnButtonClicked 5 

#define OnMenuAction1  1
#define OnMenuAction2  2
#define OnMenuAction3  3



LRESULT CALLBACK SowftwareMainProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hinst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);

void MainWndAddMenus(HWND hwnd);
void MainWndAddWidgets(HWND hwnd);