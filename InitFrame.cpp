#include <iostream>
#include "InitFrame.h"

InitFrame::InitFrame()
	:m_hIstance(GetModuleHandle(nullptr))
{
	const char* CLASS_NAME = "Ai-Black-Jack";

	WNDCLASS wndClass = {};
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hInstance = m_hIstance;
	wndClass.hIcon = LoadIcon(m_hIstance, MAKEINTRESOURCE(IDI_IconSmall));
	wndClass.hCursor = LoadCursor(m_hIstance, IDC_ARROW);
	wndClass.lpfnWndProc = WindowProc;

	RegisterClass(&wndClass);

	DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU; 

	int width = 640;
	int height = 480; 

	RECT rect;
	rect.left = 250;
	rect.top = 250;
	rect.right = rect.left + width;
	rect.bottom = rect.top + height;

	AdjustWindowRect(&rect, style, false);

	m_hWnd = CreateWindowEx(
		0,
		CLASS_NAME,
		"Title",
		style, 
		rect.left,
		rect.top, 
		rect.right - rect.left,
		rect.bottom - rect.top,
		NULL,
		NULL,
		m_hIstance,
		NULL
	);

	ShowWindow(m_hWnd, SW_SHOW);
}

bool InitFrame::ProcessMessages()
{
	MSG msg = {};
	while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT) {
			return false;
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return true;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	/*case WM_CREATE:
		HBITMAP hImage = (HBITMAP)LoadImage(NULL, "test.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE)*/
		
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

InitFrame::~InitFrame()
{
	const char* CLASS_NAME = "Ai-Black-Jack";
	UnregisterClass(CLASS_NAME, m_hIstance);
}