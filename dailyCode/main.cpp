#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<sstream>
#include<stack>
#include<cmath>
#include<set>


int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int nData = 10;
	char strTmp[30] = "ajbksd'";
	char strPaint[64]{};

	sprintf_s(strPaint, 64, "%s = %d", strTmp, nData);

	std::cout << strPaint << std::endl;
	return 0;
}
