#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>

#include "Find_Peak_Element_162.h"
/*
*/
int main(void)
{
	{
		using namespace std;
		vector<int> testCase = { 1,2,1,3,5,6,4 };
		vector<int> testCase2 = { 1,2,0 };

		Solution s = Solution();
		cout << s.findPeakElement(testCase);

	}


	return 0;
}

