class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr)
			return true;
		return isSymmetric(root->left, root->right);
	}
	bool isSymmetric(TreeNode* T_Left, TreeNode* T_Right) {
		if (T_Left == nullptr && T_Right == nullptr)
			return true;
		if (T_Left == nullptr || T_Right == nullptr)
			return false;
		if (T_Left->val != T_Right->val)
			return false;
		return isSymmetric(T_Left->left, T_Right->right) && isSymmetric(T_Left->right, T_Right->left);
	}

};