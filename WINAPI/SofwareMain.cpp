#include <Windows.h>
#include "SoftwareDefinitions.h"

LRESULT CALLBACK SowftwareMainProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hinst, HICON Icon, LPCWSTR Name, WNDPROC Procedure); 


int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {

	WNDCLASS SoftwareMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hinst, LoadIcon(NULL, IDI_QUESTION),
		L"MainWindClass", SowftwareMainProcedure); 

	if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
	MSG SoftwareMainMessage = { 0 }; 

	CreateWindow(L"MainWindClass", L"First c++ Window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 250, NULL, NULL, NULL, NULL); 
	while (GetMessage(&SoftwareMainMessage, NULL, NULL, NULL)) { 
		TranslateMessage(&SoftwareMainMessage);
		DispatchMessage(&SoftwareMainMessage);
	}
	return 0; 

}

WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor,  HINSTANCE hinst, HICON Icon, LPCWSTR Name, WNDPROC Procedure) {

	WNDCLASS NWC = { 0 };

	NWC.hIcon = Icon;
	NWC.hCursor = Cursor;
	NWC.hInstance = hinst;
	NWC.lpszClassName = Name; 
	NWC.hbrBackground = BGColor; 
	NWC.lpfnWndProc = Procedure; 

	return NWC; 

}
LRESULT CALLBACK  SowftwareMainProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	
	case WM_COMMAND:
		switch (wp) {

		case OnMenuAction1:
			MessageBoxA(hwnd, "Menu 1 was clicked ", "Menu worked", MB_OK); 
			break;
		case OnMenuAction2:
			MessageBoxA(hwnd, "Menu 2 was clicked ", "Menu worked", MB_OK);
			break;
		case OnMenuAction3:
			MessageBoxA(hwnd, "Menu 3 was clicked ", "Menu worked", MB_OK);
			break;
		
		case OnButtonClicked: 
			SetWindowTextA(heditControl, "");
			break;
		
		
		case OnExitSoftware:
			PostQuitMessage(0);
			break;

		default:break; 
		}
		break;
	
	case WM_CREATE:
		MainWndAddMenus(hwnd);
		MainWndAddWidgets(hwnd);
		break;
	case WM_DESTROY: PostQuitMessage(0);
		break;

	default: return DefWindowProc(hwnd, msg, wp, lp);
		break;

	}
	return 0; 
}

void MainWndAddMenus(HWND hwnd) {
	HMENU RootMENU = CreateMenu();
	HMENU SubMENU = CreateMenu();
	HMENU SubActionMenu = CreateMenu(); 

	
	AppendMenu(SubActionMenu, MF_STRING, OnMenuAction1, L" MENU1 ");
	AppendMenu(SubActionMenu, MF_STRING, OnMenuAction2, L" MENU2 ");
	AppendMenu(SubActionMenu, MF_STRING, OnMenuAction3, L" MENU3 ");
	
	
	AppendMenu(SubMENU, MF_SEPARATOR, NULL, NULL);

	AppendMenu(SubMENU, MF_POPUP, (UINT_PTR)SubActionMenu, L"Button =) ");
	AppendMenu(SubActionMenu, MF_STRING, OnExitSoftware, L" Exit ");
	
	AppendMenu(RootMENU, MF_POPUP, (UINT_PTR)SubMENU, L"File "); 
	
	
	SetMenu(hwnd, RootMENU);
}

void MainWndAddWidgets(HWND hwnd) {

	CreateWindowW(L"static", L"Hello Window", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 5, 480, 20, hwnd, NULL, NULL, NULL);

	heditControl = CreateWindowW(L"edit", L"This is edit control", WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_VSCROLL, 5, 30 , 490, 130, hwnd, NULL, NULL, NULL);

	CreateWindowW(L"button", L"CLEAR", WS_VISIBLE | WS_CHILD, 5, 1 , 120, 30, hwnd, (HMENU)OnButtonClicked, NULL, NULL, NULL);

}