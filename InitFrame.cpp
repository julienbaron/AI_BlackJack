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

bool LoadAndBlitMap(LPCSTR name, HDC hWnDC) {
	HBITMAP bm;
	bm = (HBITMAP)::LoadImage(NULL, name, IMAGE_BITMAP, 200, 200, LR_LOADFROMFILE);
	if (bm) {
		HDC hLocalDC = ::CreateCompatibleDC(hWnDC);
		BITMAP qBitmap;
		auto iReturn = GetObject(reinterpret_cast<HGDIOBJ>(bm), sizeof(BITMAP),
			reinterpret_cast<PVOID> (&qBitmap));
		HBITMAP hOldBitmp = (HBITMAP)::SelectObject(hLocalDC, bm);
		BOOL qRetBlit = ::BitBlt(hWnDC, 200, 200, qBitmap.bmWidth, qBitmap.bmHeight, hLocalDC, 0, 0, SRCCOPY);
		::SelectObject(hLocalDC, hOldBitmp);
		return true;
	}
}


LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	switch (uMsg)
	{
		
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		LoadAndBlitMap("cardBack_red5.bmp", hdc);
		EndPaint(hWnd, &ps);
		return 0;
	}


	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

InitFrame::~InitFrame()
{
	const char* CLASS_NAME = "Ai-Black-Jack";
	UnregisterClass(CLASS_NAME, m_hIstance);
}