#ifndef ___Binary_Tree_Inorder_Traversal_194_h___
#define ___Binary_Tree_Inorder_Traversal_194_h___

/**
 * Definition for a binary tree node.
 * struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
    vector<int> inorder_traversal_helpter(TreeNode* node, vector<int>& res) {
        if (node == nullptr)
            return res;

        inorder_traversal_helpter(node->left, res);
        res.push_back(node->val);
        inorder_traversal_helpter(node->right, res);
        return res;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        return inorder_traversal_helpter(root, result);
    }
};
#endif