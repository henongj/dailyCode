#pragma once

#include<Windows.h>
#include"winapi.h"

class C_WINAPI
{
private:
	static C_WINAPI* m_pAPI;
	
	HINSTANCE m_hInstance;
	HWND m_hWnd;

	int m_nData1;
	
	LRESULT(C_WINAPI::*m_arMSGFUNC[WM_USER])(HWND hWnd, WPARAM wParam, LPARAM lParam);

private:
	void initMsgFunc();
	LRESULT OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam);
	LRESULT OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam);

private:
	C_WINAPI() = default;
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK apiProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	
public:
	static void createAPI();
	static C_WINAPI* getAPI();
	static void releaseAPI();

public:
	~C_WINAPI() = default;

	C_WINAPI& operator=(const C_WINAPI&) = delete;
	C_WINAPI(const C_WINAPI&) = delete;
	
	bool init(HINSTANCE hInstance);
	void updateMsg();

	static void setWindowStyle(DWORD dwStyle);
	
};
