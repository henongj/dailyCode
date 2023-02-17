
//https://leetcode.com/problems/minimum-distance-between-bst-nodes/
//783. Minimum Distance Between BST Nodes


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
	int minDiffInBST(TreeNode* root) {
		int min = INT_MAX;
		int prev = -1;
		inorder(root, min, prev);
		return min;
	}
	void inorder(TreeNode* root, int& min, int& prev) {
		if (root == nullptr) return;
		inorder(root->left, min, prev);
		if (prev != -1) {
			int diff = root->val - prev;
			if (diff < min) min = diff;
		}
		prev = root->val;
		inorder(root->right, min, prev);
	}

};

/* 肋给等 立辟过
class Solution {
public:
	int minDiffInBST(TreeNode* root) {
		int nMinimumDifference{};
		int nValue1{};
		int nValue2{};
		priority_queue<int, vector<int>, greater<int>> pq;
		funcInorderBinarySearchTraversal(root, pq);

		nValue1 = pq.top();
		pq.pop();
		nValue2 = pq.top();
		pq.pop();
		cout << nValue1 << " " << nValue2 << endl;
		nMinimumDifference = nValue2 - nValue1;

		return nMinimumDifference;
	}
	void funcInorderBinarySearchTraversal(TreeNode* root, priority_queue<int, vector<int>, greater<int>>& pq) {
		if (root->left!= nullptr)
			funcInorderBinarySearchTraversal(root->left, pq);
		pq.push(root->val);
		if (root->right != nullptr)
			funcInorderBinarySearchTraversal(root->right, pq);
	}
};
*/