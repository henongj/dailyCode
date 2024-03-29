#include "winapi.h"

C_WINAPI* C_WINAPI::m_pApi = nullptr;

void C_WINAPI::createApi()
{
    if (!m_pApi)
        m_pApi = new C_WINAPI{};
}

C_WINAPI* C_WINAPI::getApi()
{
    return m_pApi;
}

void C_WINAPI::releaseApi()
{
    if (m_pApi)
    {
        delete m_pApi;
        m_pApi = nullptr;
    }
}

HRESULT C_WINAPI::InitWindow(HINSTANCE hInstance, int nCmdShow)
{
    m_hInst = hInstance;

    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = m_hInst;
    wcex.hIcon = LoadIcon(m_hInst, (LPCTSTR)IDI_TUTORIAL1);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = L"TutorialWindowClass";
    wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_TUTORIAL1);
    if (!RegisterClassEx(&wcex))
        return E_FAIL;

    // Create window
    RECT rc = { 0, 0, 640, 480 };
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
    m_hWnd = CreateWindow(L"TutorialWindowClass", L"Direct3D 11 Tutorial 5", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, m_hInst,
        NULL);
    if (!m_hWnd)
        return E_FAIL;

    ShowWindow(m_hWnd, nCmdShow);

    m_pDirectx = new C_DIRECTX{};
    m_pDirectx->InitDevice(m_hWnd);

    return S_OK;
}


LRESULT CALLBACK C_WINAPI::myProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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

LRESULT CALLBACK C_WINAPI::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return m_pApi->myProc(hWnd, message, wParam, lParam);

}

void C_WINAPI::updateMsg()
{
    for (int i = 0; i < 100; i++)
    {
        m_arObject[i].init(rand() % 2);

        m_arObject[i].setPosition( (rand() % 100) - 50.0f, (rand() % 100) - 50.0f, (rand() % 100) - 50.0f);
    }

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
            if (GetAsyncKeyState('A') & 0x8000)
                m_cCamera.addRotationYaw(-0.1f);
            if (GetAsyncKeyState('D') & 0x8000)
                m_cCamera.addRotationYaw(0.1f);
            if (GetAsyncKeyState('W') & 0x8000)
                m_cCamera.moveFoward(0.1f);
            if (GetAsyncKeyState('S') & 0x8000)
                m_cCamera.moveBackward(0.1f);


            for (int i = 0; i < 100; i++)
            {
                m_arObject[i].update();
            }

            for (int i = 0; i < 100; i++)
            {
                m_pDirectx->setRenderObject(m_arObject[i].getMeshId(), m_arObject[i].getMatrix());
            }

            m_cCamera.update();
            m_pDirectx->setViewMatrix(m_cCamera.getMatView());

            m_pDirectx->Render();
        }
    }

    m_pDirectx->CleanupDevice();
    delete m_pDirectx;
    m_pDirectx = nullptr;

}