
//https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/
//2244. Minimum Rounds to Complete All Tasks
#ifndef ___Minimum_Rounds_to_Complete_All_Tasks_2244_h___
#define ___Minimum_Rounds_to_Complete_All_Tasks_2244_h___
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
using namespace std;
class Solution {
public:
	int minimumRounds(vector<int>& tasks) {
		int n = tasks.size();
		int max_len = 100001;
		int round = 0;
		unordered_map <int, int> task_count; // task_count[task] = count

		for (int i = 0; i < n; i++)
			task_count[tasks[i]]++;

		vector<int> memo(max_len, 0);
		memo[1] = -1; memo[2] = 1; memo[3] = 1; memo[4] = 2;

		for (int i = 5; i < max_len; i++)
			memo[i] = min(memo[i - 2], memo[i - 3]) + 1;

		for (auto i : task_count)
		{
			cout << i.first << " " << i.second << endl;
			int r = memo[i.second];
			if (r == -1)
				return -1;
			round += r;
		}

		return round;

	}
};
#endif //___Minimum_Rounds_to_Complete_All_Tasks_2244_h___