//https://leetcode.com/problems/sum-root-to-leaf-numbers/
//___Sum_Root_to_Leaf_Numbers_129_h___
#ifndef ___Sum_Root_to_Leaf_Numbers_129_h___
#define ___Sum_Root_to_Leaf_Numbers_129_h___
#include<vector>
#include<iostream>
using namespace std;
class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(NULL), right(NULL) {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
	int get_path_sum(const vector<int>& path)
	{
		int sum = 0;
		for (int i = 0; i < path.size(); i++)
			sum = (sum * 10) + path[i];
		return sum;
	}
	void get_paths(TreeNode* root, vector<int>& path, int& sum)
	{
		if (!root)
			return;

		path.push_back(root->val);

		// nullptr일 때 get_path_sum 하면 left, right 각각 두 번 더하게 된다
		if (!(root->left) && !(root->right))
			sum += get_path_sum(path);

		if (root->left)
			get_paths(root->left, path, sum);
		if (root->right)
			get_paths(root->right, path, sum);

		path.pop_back();
	}
	int sumNumbers(TreeNode* root) {
		int sum = 0;
		vector<int> path;
		get_paths(root, path, sum);
		return sum;
	}
};
#endif