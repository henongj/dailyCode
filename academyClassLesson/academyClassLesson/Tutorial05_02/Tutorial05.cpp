
#include "winapi.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    C_WINAPI::createApi();
    C_WINAPI::getApi()->InitWindow(hInstance, nCmdShow);
    C_WINAPI::getApi()->updateMsg();
    
    C_WINAPI::releaseApi();

    
    return 0;
}


