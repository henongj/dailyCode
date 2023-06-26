#include "winapi.h"
#include"resource.h"

C_WINAPI* C_WINAPI::m_pAPI = nullptr;

bool C_WINAPI::init(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = C_WINAPI::WndProc;// (WNDPROC)apiProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ACADEMYAPI));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;// MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
	wcex.lpszClassName = L"className";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	RegisterClassExW(&wcex);

	//WS_TILEDWINDOW
	m_hWnd = CreateWindowW(L"className", nullptr, (WS_OVERLAPPED | WS_CAPTION | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX),
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
	
	if (!m_hWnd)
		return false;

	ShowWindow(m_hWnd, SW_SHOWDEFAULT);
	UpdateWindow(m_hWnd);

	return true;
}

void C_WINAPI::updateMsg()
{
	MSG msg;

	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void C_WINAPI::setWindowStyle(DWORD dwStyle)
{
	SetWindowLongPtr(m_pAPI->m_hWnd, GWL_STYLE, dwStyle);
}

void C_WINAPI::initMsgFunc()
{
	m_arMSGFUNC[WM_PAINT] = &C_WINAPI::OnPaint;
	m_arMSGFUNC[WM_DESTROY] = &C_WINAPI::OnDestroy;
}

LRESULT C_WINAPI::OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
	EndPaint(hWnd, &ps);
	
	return S_OK;
}

LRESULT C_WINAPI::OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
	
	return S_OK;
}

LRESULT CALLBACK C_WINAPI::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return m_pAPI->apiProc(hWnd, message, wParam, lParam);
}

LRESULT C_WINAPI::apiProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if(message < WM_USER && m_arMSGFUNC[message])
		return (this->*m_arMSGFUNC[message])(hWnd, wParam, lParam);

	return DefWindowProc(hWnd, message, wParam, lParam);
}

void C_WINAPI::createAPI()
{
	if(m_pAPI == nullptr)
	{
		m_pAPI = new C_WINAPI();
		m_pAPI->initMsgFunc();
	}
}

C_WINAPI* C_WINAPI::getAPI()
{
	return m_pAPI;
}

void C_WINAPI::releaseAPI()
{
	if (m_pAPI)
	{
		delete m_pAPI;
		m_pAPI = nullptr;
	}
}
