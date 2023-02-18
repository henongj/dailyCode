
//https://leetcode.com/problems/invert-binary-tree/submissions/900224854/
//226. Invert Binary Tree
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
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr)
			return root;

		funcTraversalForInvertTree(root);
		return root;
	}
	void funcTraversalForInvertTree(TreeNode* root)
	{
		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;

		if (root->left != nullptr)
			funcTraversalForInvertTree(root->left);
		if (root->right != nullptr)
			funcTraversalForInvertTree(root->right);
	}
};