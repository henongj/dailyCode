#ifndef ___Binary_Tree_Level_Order_Traversal_102_h___
#define ___Binary_Tree_Level_Order_Traversal_102_h___

//https ://leetcode.com/problems/binary-tree-level-order-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class TreeSolution {
public:

	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		/* 왼쪽 순회였으면 오른쪽, 오른쪽 순회였으면 왼쪽 */
		queue<TreeNode*> q;
		vector<vector<int>> result = {};
		bool is_left = true;

		if (root == nullptr)
			return result;
		q.push(root);

		while (!q.empty()) {
			int size = q.size();
			vector<int> same_level_value = {};
			for (int i = 0; i < size; i++) {
				TreeNode* node = q.front();
				q.pop();
				if (node == nullptr) continue;
				same_level_value.push_back(node->val);
				q.push(node->left);
				q.push(node->right);
			}

			// 왼쪽 순회였으면 오른쪽, 오른쪽 순회였으면 왼쪽
			if (!same_level_value.empty())
			{
				if (is_left == false)
					reverse(same_level_value.begin(), same_level_value.end());
				result.push_back(same_level_value);
				is_left = !is_left;
			}
		}
		return result;
	}
};

#endif