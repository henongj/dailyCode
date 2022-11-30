
#ifndef ___Sum_of_Left_Leaves_404_h___
#define ___Sum_of_Left_Leaves_404_h___
//https://leetcode.com/problems/sum-of-left-leaves/?envType=study-plan&id=programming-skills-i
// 404. Sum of Left Leaves
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<sstream>
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

	void get_sum_of_left_leaves(TreeNode* node, int& sum)
	{
		if (node == nullptr)
			return;
		// 좌측 자식이 있는데 얘가 리프노드라면 합산
		if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr)
			sum += node->left->val;
		get_sum_of_left_leaves(node->left, sum);
		get_sum_of_left_leaves(node->right, sum);
	}
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int sum = 0;

		get_sum_of_left_leaves(root, sum);
		return sum;
	}
};

#endif // ___Sum_of_Left_Leaves_404_h___