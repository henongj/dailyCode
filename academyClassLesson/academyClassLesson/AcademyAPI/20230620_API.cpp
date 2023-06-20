// WindowsProject1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h" 
#include"winapi.h"


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	C_WINAPI::createAPI();
	C_WINAPI::getAPI()->init(hInstance);
	C_WINAPI::getAPI()->updateMsg();



	
	C_WINAPI::releaseAPI();
}
