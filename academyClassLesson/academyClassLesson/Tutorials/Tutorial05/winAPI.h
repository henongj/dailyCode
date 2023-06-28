#pragma once

#include <windows.h>
#include "resource.h"

class C_WINAPI
{
private:
	static C_WINAPI* m_pWinAPI;
	HINSTANCE m_hInst;
	HWND m_hWnd;

	LRESULT(C_WINAPI::* m_msgFunction[WM_USER])(HWND hWnd, WPARAM wParam, LPARAM lParam);
	
private:
	C_WINAPI() = default;

private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT classProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	void initMsgFunction(void);
	LRESULT onPaint(HWND hWnd, WPARAM wParam, LPARAM lParam);
	LRESULT onDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam);

public:
	static void createIstance(void);
	static void releaseInstance(void);
	static C_WINAPI* getAPI(void);

public:
	HRESULT init(HINSTANCE hInstance);
	void updateMessage(void);
};