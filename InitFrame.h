#pragma once
#include <Windows.h>
#include "resource.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class InitFrame
{
private: 
	HINSTANCE m_hIstance;
	HWND m_hWnd; 

public:
	InitFrame();
	~InitFrame();

	bool ProcessMessages();
};

