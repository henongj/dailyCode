#pragma once
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
#include <fstream>
#include<functional>

using namespace std;

namespace accessTest
{
	void test(void)
	{
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

		int arr[3][3]{ {1,2,3},{4,5,6},{7,8,9} };

		int* p = arr[0];
		for (int i = 0; i < 10; i++)
		{
			cout << *(p + i) << endl;
			p = arr[0] + i;
		}

		int* p2 = arr[0] + 100;

		printf("%d\n", *p);
		printf("%p\n", *p2);

		*p2 = 3;
		printf("%p\n", *p2);

	}
	
}

