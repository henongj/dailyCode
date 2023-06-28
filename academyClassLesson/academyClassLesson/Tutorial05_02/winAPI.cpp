#include "winAPI.h"

C_WINAPI* C_WINAPI::m_pWinAPI = nullptr;

LRESULT C_WINAPI::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return m_pWinAPI->classProc(hWnd, message, wParam, lParam);
}

LRESULT C_WINAPI::classProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message)
    {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return S_OK;
}

void C_WINAPI::createAPI(void)
{
    if (!m_pWinAPI)
        m_pWinAPI = new C_WINAPI{};
}

void C_WINAPI::releaseAPI(void)
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
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_TUTORIAL1);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = L"Æ©ÅçÀ©Å¬";
    wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_TUTORIAL1);
    if (!RegisterClassEx(&wcex))
        return E_FAIL;

    // Create window
    m_hInstance = hInstance;
    RECT rc = { 0, 0, 640, 480 };
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
    m_hWnd = CreateWindow(L"Æ©ÅçÀ©Å¬", L"Æ©Åç 5¹ø", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, hInstance,
        NULL);
    if (!m_hWnd)
        return E_FAIL;

	ShowWindow(m_hWnd, SW_SHOWDEFAULT);

    return S_OK;
}

void C_WINAPI::updateMSG(void)
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
            //Render();
        }
    }
}

HWND C_WINAPI::getHWNdD(void)
{
    return m_hWnd;
}
