//https://leetcode.com/problems/balanced-binary-tree/?envType=study-plan&id=programming-skills-ii
//110. Balanced Binary Tree
#ifndef ___Balanced_Binary_Tree_110_h___
#define ___Balanced_Binary_Tree_110_h___
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

	int height(TreeNode* node)
	{
		if (node == nullptr)
			return 0;
		return max(height(node->left), height(node->right)) + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (root == nullptr)
			return true;
		int left = height(root->left);
		int right = height(root->right);
		if (abs(left - right) > 1)
			return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}
};

#endif // ___Balanced_Binary_Tree_110_h___