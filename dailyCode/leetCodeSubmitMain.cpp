#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include"leetCodeProblem/Count_Odd_Numbers_in_an_Interval_Range_1523.h"
/*
* #include "Find_Peak_Element_162.h"
*/

using namespace std;

/*

*/
struct testCase
{
	
	/*
	Input: low = 3, high = 7
	Output: 3
	Explanation: The odd numbers between 3 and 7 are [3,5,7].
	Input: low = 8, high = 10
	Output: 1
	Explanation: The odd numbers between 8 and 10 are [9].
	*/
	pair<int, int> test_case1 = pair<int, int>(3, 7);
	pair<int, int> test_case2 = pair<int, int>(8, 10);

};

int main(void)
{
	{
		using namespace std;
		
		// testCase set struct
		testCase test_case;
		pair<int,int> p = test_case.test_case1;
		
		Solution s = Solution();
		
		cout << s.countOdds(p.first , p.second ) << endl;

	}


	return 0;
}
