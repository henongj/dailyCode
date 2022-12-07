
//https://leetcode.com/problems/range-sum-of-bst/
//938. Range Sum of BST
#ifndef ___Range_Sum_of_BST_938_h___
#define ___Range_Sum_of_BST_938_h___
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
	void preorder_traversal(TreeNode* node, int& sum, int low, int high)
	{
		if (node == nullptr)
			return;

		if (low <= node->val && node->val <= high)
			sum += node->val;

		preorder_traversal(node->left, sum, low, high);
		preorder_traversal(node->right, sum, low, high);

	}
	int rangeSumBST(TreeNode* root, int low, int high) {
		int sum = 0;
		preorder_traversal(root, sum, low, high);
		return sum;
	}
};

#endif // ___Range_Sum_of_BST_938_h___