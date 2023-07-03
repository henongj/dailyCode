#pragma once

#include <windows.h>
#include "resource.h"
#include "directX.h"
#include "object.h"

class C_WINAPI
{
private:
	static C_WINAPI*		m_pApi;
	HINSTANCE               m_hInst;
	HWND                    m_hWnd;
	C_DIRECTX				* m_pDirectx;

	C_OBJECT m_arObject[2];
private:
	C_WINAPI() = default;

private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK myProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
	static void createApi();
	static C_WINAPI* getApi();
	static void releaseApi();

	HRESULT InitWindow(HINSTANCE hInstance, int nCmdShow);
	void updateMsg();
};