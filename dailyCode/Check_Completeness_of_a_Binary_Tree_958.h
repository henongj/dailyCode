#pragma once

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
		
		bool isRight = true;

		isRightBinaryTree(root, &isRight);

		return isRight;
	}
	
	void isRightBinaryTree(TreeNode* node, bool* bResult)
	{
		TreeNode* tLeft = node->left;
		TreeNode* tRight = node->right;

		if (tLeft == nullptr && tRight != nullptr)
			*bResult = false;

		if(tLeft != nullptr)
			isRightBinaryTree(tLeft, bResult);
		
		if (tRight != nullptr)
			isRightBinaryTree(tRight, bResult);
		
	}
};

/*

루트 -> 좌우

왼쪽 nullptr 오른쪽 not nullptr = false
왼쪽 not nullptr , 오른쪽 nullptr  = true

둘다 nullptr =  정상
둘 다 있음 = 정상

*/