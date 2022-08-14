#pragma once
#include <Windows.h>
#include "resource.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
bool LoadAndBlitMap(LPCSTR name, HDC hWnDC, int width, int height, int pwidth, int pheight);

class InitFrame
{
private: 
	HINSTANCE m_hIstance;
	HWND m_hWnd;
	int width = 640;
	int height = 480;

public:
	InitFrame();
	~InitFrame();
	bool ProcessMessages();
};

