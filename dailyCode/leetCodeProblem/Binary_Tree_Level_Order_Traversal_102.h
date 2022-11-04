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

class Solution {
public:

	vector<vector<int>> levelOrder(TreeNode* root) {

		queue<TreeNode*> q;
		vector<vector<int>> result;

		q.push(root);
		while (!q.empty()) {
			int size = q.size();
			vector<int> same_level_value;
			for (int i = 0; i < size; i++) {
				TreeNode* node = q.front();
				q.pop();
				if (node == nullptr) continue;
				same_level_value.push_back(node->val);
				q.push(node->left);
				q.push(node->right);
			}
			if (!same_level_value.empty()) result.push_back(same_level_value);
		}


		return result;
	}
};

/*

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

*/

#endif