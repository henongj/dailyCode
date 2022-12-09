
//https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
//1026. Maximum Difference Between Node and Ancestor
#ifndef ___Maximum_Difference_Between_Node_and_Ancestor_1026_h___
#define ___Maximum_Difference_Between_Node_and_Ancestor_1026_h___
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
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int get_maximum_difference(TreeNode* root, int min_val, int max_val) {

		if (root == nullptr)
			return max_val - min_val;

		min_val = min(min_val, root->val);
		max_val = max(max_val, root->val);

		return max(get_maximum_difference(root->left, min_val, max_val), get_maximum_difference(root->right, min_val, max_val));
	}
	int maxAncestorDiff(TreeNode* root) {
		int min_val = 1000000;
		int max_val = -1000000;
		int max_diff = get_maximum_difference(root, min_val, max_val);

		return max_diff;
	}
};

#endif //___Maximum_Difference_Between_Node_and_Ancestor_1026_h___