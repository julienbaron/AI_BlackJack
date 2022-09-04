#include <iostream>
#include "InitFrame.h"
#include "Card.h"
#include "Manager.h"
#include <string>
#include <typeinfo>
#include <memory>

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

	width = 640;
	height = 480; 

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


//TODO : try to wrapp this method 
bool LoadAndBlitMap(LPCSTR name, HDC hWnDC, int width, int height, int pwidth, int pheight) {
	HBITMAP bm;
	bm = (HBITMAP)::LoadImage(NULL, name, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	if (bm) {

		HDC hLocalDC = ::CreateCompatibleDC(hWnDC);
		BITMAP qBitmap;
		auto iReturn = GetObject(reinterpret_cast<HGDIOBJ>(bm), sizeof(BITMAP),
			reinterpret_cast<PVOID> (&qBitmap));
		HBITMAP hOldBitmp = (HBITMAP)::SelectObject(hLocalDC, bm);
		BOOL qRetBlit = ::BitBlt(hWnDC, pwidth, pheight, qBitmap.bmWidth, qBitmap.bmHeight, hLocalDC, 0, 0, SRCCOPY);
		::SelectObject(hLocalDC, hOldBitmp);
		DeleteObject(hOldBitmp);
		DeleteDC(hLocalDC);
		return true;
	}
	else {
		//TODO: get value of a long pointer 
		std::cerr << "error occurs during the loading of some sprite";
		return false;
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

	case WM_ERASEBKGND: {
		RECT rect;
		HDC hdc = (HDC)(wParam);

		GetWindowRect(hWnd, &rect);
		LoadAndBlitMap("GameBoard.bmp", hdc, 640, 480, 0, 0);
		
		return TRUE;
	}

	case WM_PAINT:
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		LoadAndBlitMap("cardBack_red5.bmp", hdc, 70, 90, 475, 95);
		HFONT hFont1 = CreateFont(30, 0, 0, 0, FW_MEDIUM, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Impact"));
		HFONT hFontOriginal = (HFONT)SelectObject(hdc, hFont1);
		SetBkMode(hdc, TRANSPARENT);
		SetTextColor(hdc, RGB(255, 255, 255));
		TextOut(hdc, 10, 10, TEXT("BANK:"), strlen("BANK:"));
		
		if (wParam == 0) {
			std::cout << "aaa";
			auto a = std::move((std::unique_ptr<Chip>*)lParam);
			if (a != NULL) {
				a->get();
				std::cout<<"bb";
			}

		}
			
		//std::unique_ptr<Chip> &&test = std::move(*(std::unique_ptr<Chip>*)lParam);
		//auto a = test.get();
		//std::move(*((std::unique_ptr<Chip>*) lParam));
		/*Card* card = (Card*)lParam;
		std::cout << typeid(card).name() << endl;*/
		DeleteObject(hFont1);
		EndPaint(hWnd, &ps);
		return 0;
	}


	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

InitFrame::

InitFrame::~InitFrame()
{
	const char* CLASS_NAME = "Ai-Black-Jack";
	UnregisterClass(CLASS_NAME, m_hIstance);
}