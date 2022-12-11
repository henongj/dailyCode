
// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// 124. Binary Tree Maximum Path Sum
#ifndef ___Binary_Tree_Maximum_Path_Sum_124_h___
#define ___Binary_Tree_Maximum_Path_Sum_124_h___
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
	void get_max_Path_Sum(TreeNode* root, int& max_sum) {
		if (root == nullptr) return;
		int left = 0;
		int right = 0;
		get_max_Path_Sum(root->left, max_sum);
		get_max_Path_Sum(root->right, max_sum);
		if (root->left != nullptr) {
			left = max(0, root->left->val);
		}
		if (root->right != nullptr) {
			right = max(0, root->right->val);
		}
		max_sum = max(max_sum, left + right + root->val);
		root->val += max(left, right);
	}
	int maxPathSum(TreeNode* root) {
		int maxSum = -1000000;
		get_max_Path_Sum(root, maxSum);
		return maxSum;
	}
};


#endif // ___Binary_Tree_Maximum_Path_Sum_124_h___
