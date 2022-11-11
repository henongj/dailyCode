
//112 https://leetcode.com/problems/path-sum/
#ifndef ___Path_Sum_112_h___
#define ___Path_Sum_112_h___

 // Definition for a binary tree node.
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
    void tree_traversal_get_sum(TreeNode* node, int sum, const int& targetSum, bool& result)
    {
        if (node == nullptr)
            return;
        tree_traversal_get_sum(node->left, sum + node->val, targetSum, result);
        tree_traversal_get_sum(node->right, sum + node->val, targetSum, result);

        if (node->left == nullptr && node->right == nullptr)
        {
            if (targetSum == sum + node->val)
                result = true;
            return;
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool result = false;
        if (root == nullptr)
            return 0;
        tree_traversal_get_sum(root, sum, targetSum, result);
        return result;

    }
};

#endif