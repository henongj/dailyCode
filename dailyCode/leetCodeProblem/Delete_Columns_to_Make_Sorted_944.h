
//https://leetcode.com/problems/delete-columns-to-make-sorted/
//944. Delete Columns to Make Sorted
#ifndef ___Delete_Columns_to_Make_Sorted_944_h___
#define ___Delete_Columns_to_Make_Sorted_944_h___
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
	int minDeletionSize(vector<string>& strs) {
		int count = 0;
		for (int i = 0; i < strs[0].size(); i++) {
			for (int j = 0; j < strs.size() - 1; j++) {
				if (strs[j][i] > strs[j + 1][i]) {
					count++;
					break;
				}
			}
		}
		return count;
	}
};

#endif // ___Delete_Columns_to_Make_Sorted_944_h___ 
