
#ifndef ___Binary_Tree_Preorder_Traversal_144_h___
#define ___Binary_Tree_Preorder_Traversal_144_h___
//https://leetcode.com/problems/binary-tree-preorder-traversal/description/
//144. Binary Tree Preorder Traversal
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
	void get_preorder(TreeNode* node, vector<int>& result)
	{
		if (node == nullptr)
			return;

		result.push_back(node->val);
		get_preorder(node->left, result);
		get_preorder(node->right, result);
	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		get_preorder(root, result);
		return result;
	}
};
#endif // ___Binary_Tree_Preorder_Traversal_144_h___