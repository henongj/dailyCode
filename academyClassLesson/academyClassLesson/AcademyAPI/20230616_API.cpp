﻿//// AcademyAPI.cpp : 애플리케이션에 대한 진입점을 정의합니다.
////
//#include<windowsx.h>
//
//#include "framework.h"
//#include "AcademyAPI.h"
//#define MAX_LOADSTRING 100
//
//LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//
//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//	_In_opt_ HINSTANCE hPrevInstance,
//	_In_ LPWSTR    lpCmdLine,
//	_In_ int       nCmdShow)
//{
//	UNREFERENCED_PARAMETER(hPrevInstance);
//	UNREFERENCED_PARAMETER(lpCmdLine);
//
//	WNDCLASSEXW wcex;
//
//	//등록
//	wcex.cbSize = sizeof(WNDCLASSEX);
//	wcex.style = CS_HREDRAW | CS_VREDRAW;
//	wcex.lpfnWndProc = WndProc;
//	wcex.cbClsExtra = 0;
//	wcex.cbWndExtra = 0;
//	wcex.hInstance = hInstance;
//	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ACADEMYAPI));
//	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
//	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wcex.lpszMenuName = nullptr; // MAKEINTRESOURCEW(IDC_ACADEMYAPI);
//	wcex.lpszClassName = L"className";
//	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
//
//	RegisterClassExW(&wcex);
//
//	HWND hWnd = CreateWindowExW(0, L"className", L"AcademyAPI", WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
//
//	if (!hWnd)
//		return FALSE;
//	
//	ShowWindow(hWnd, nCmdShow);
//	UpdateWindow(hWnd);
//
//	MSG msg;
//	
//	while (GetMessage(&msg, nullptr, 0, 0))
//	{
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	static int nPosX{};
//	static int nPosY{};
//	static WCHAR szKey = L'A';
//
//	switch (message)
//	{
//	case WM_KEYDOWN:
//		szKey = (WCHAR)wParam;
//		//InvalidateRgn(hWnd, nullptr, true);
//		InvalidateRect(hWnd, nullptr, true);
//		break;
//	case WM_MOUSEMOVE:
//	{
//		InvalidateRect(hWnd, nullptr, true);
//		nPosX = GET_X_LPARAM(lParam);
//		nPosY = GET_Y_LPARAM(lParam);
//		break;
//	}
//	case WM_PAINT:
//	{
//		PAINTSTRUCT ps;
//		HDC hdc = BeginPaint(hWnd, &ps);
//		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
//		
//		WCHAR szTmp[64]{};
//		swprintf_s(szTmp, 64, L"X : %d, y : %d , pressed key : %c", nPosX, nPosY, szKey);
//		TextOut(hdc, nPosX, nPosY, szTmp, 40);
//		
//		EndPaint(hWnd, &ps);
//	}
//	break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	default:
//		return DefWindowProc(hWnd, message, wParam, lParam);
//	}
//	return 0;
//}
