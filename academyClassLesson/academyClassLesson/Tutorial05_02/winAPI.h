#pragma once

#include<windows.h>
#include"Resource.h"

class C_WINAPI
{
private:
	static C_WINAPI* m_pWinAPI;
	
	HWND m_hWnd;
	HINSTANCE m_hInstance;
private:
	C_WINAPI() = default;
	
private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT classProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
	static void createAPI(void);
	static void releaseAPI(void);
	static C_WINAPI* getAPI(void);
	
public:
	HRESULT init(HINSTANCE hInstance);
	void updateMSG(void);
	HWND getHWNdD(void);
};