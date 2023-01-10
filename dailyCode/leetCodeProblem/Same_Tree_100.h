
#ifndef ___Same_Tree_100_h___
#define ___Same_Tree_100_h___
//https://leetcode.com/problems/same-tree/description/
//100. Same Tree
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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr)
			return true;
		if (p == nullptr || q == nullptr)
			return false;
		if (p->val != q->val)
			return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

	}
};
#endif // ___Same_Tree_100_h___