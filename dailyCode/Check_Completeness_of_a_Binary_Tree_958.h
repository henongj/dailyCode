#pragma once
#include<vector>
#include<queue>
//https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
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
	bool isCompleteTree(TreeNode* root) {
		if (root == nullptr)
			return true;
		std::queue<TreeNode*> que;
		que.push(root);
		bool flag = false;
			
		while (!que.empty())
		{
			TreeNode* cur = que.front();
			que.pop();
			if (cur == nullptr)
			{
				flag = true;
				continue;
			}
			if (flag)
				return false;
			que.push(cur->left);
			que.push(cur->right);
		}

		return true;
	}

};

/*

��Ʈ -> �¿�

���� nullptr ������ not nullptr = false
���� not nullptr , ������ nullptr  = true

�Ѵ� nullptr =  ����
�� �� ���� = ����

*/