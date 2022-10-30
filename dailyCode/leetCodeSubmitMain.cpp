#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include "word_search_79.h"
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

		

		Solution s = Solution();

		/*
		printVector2D(t.testCase1);
		printVector2D(t.testCase3);
		*/
		
		cout << s.exist(t.testCase1, t.testCaseWord2) << endl;

	}


	return 0;
}


