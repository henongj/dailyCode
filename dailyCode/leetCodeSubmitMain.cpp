#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include"world_search_DFS_79.h"
/*
* #include "Find_Peak_Element_162.h"
*/

void printVector2D(const std::vector<std::vector<char>>& v)
{
	for (auto i : v)
	{
		for (auto j : i)
		{
			std::cout << j << " ";
		}
		std::cout << "\n";
	}
}

int main(void)
{
	{
		using namespace std;
		
		// testCase set struct
		testCase t;

		
		cout << s.exist(t.testCase1, t.testCaseWord1) << endl;

	}


	return 0;
}
