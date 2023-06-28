#include "winAPI.h"

C_WINAPI* C_WINAPI::m_pWinAPI = nullptr;

LRESULT C_WINAPI::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return C_WINAPI::getAPI()->classProc(hWnd, message, wParam, lParam);
}

LRESULT C_WINAPI::classProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    if (message < WM_USER && m_msgFunction[message])
        return (this->*m_msgFunction[message])(hWnd, wParam, lParam);
    
    return DefWindowProc(hWnd, message, wParam, lParam);
}

void C_WINAPI::initMsgFunction(void)
{
	m_msgFunction[WM_PAINT] = &C_WINAPI::onPaint;
	m_msgFunction[WM_DESTROY] = &C_WINAPI::onDestroy;
	
}

LRESULT C_WINAPI::onPaint(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	hdc = BeginPaint(hWnd, &ps);
	EndPaint(hWnd, &ps);

	return 0;
}

LRESULT C_WINAPI::onDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    PostQuitMessage(0);
	
    return S_OK;
}

void C_WINAPI::createIstance(void)
{
    if (!m_pWinAPI)
        m_pWinAPI = new C_WINAPI{};
}

void C_WINAPI::releaseInstance(void)
{
    if (m_pWinAPI)
    {
		delete m_pWinAPI;
        m_pWinAPI = nullptr;
    }
}

C_WINAPI* C_WINAPI::getAPI(void)
{
    return m_pWinAPI;
}

HRESULT C_WINAPI::init(HINSTANCE hInstance)
{
    // Register class
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = C_WINAPI::WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_TUTORIAL1);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = L"winAPI";
    wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_TUTORIAL1);
    if (!RegisterClassEx(&wcex))
        return E_FAIL;

    // Create window
    m_hInst = hInstance;
    RECT rc = { 0, 0, 640, 480 };
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
    m_hWnd = CreateWindow(L"winAPI", L"directXClassTutorial05", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, hInstance,
        NULL);
    if (!m_hWnd)
        return E_FAIL;

    initMsgFunction();

    ShowWindow(m_hWnd, SW_SHOWDEFAULT);

    return S_OK;
}

void C_WINAPI::updateMessage(C_DirectX* pRenderer)
{
    MSG msg = { 0 };

    while (WM_QUIT != msg.message)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            pRenderer->renderFrame();
        }
    }
}

HWND C_WINAPI::getHWND(void)
{
    return m_hWnd;
}
