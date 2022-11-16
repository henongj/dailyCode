
// https://leetcode.com/problems/path-sum-ii/
//113. 
#ifndef ___Path_Sum_II_113_h___
#define ___Path_Sum_II_113_h___
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    inline int get_sum_in_vector(const vector<int>& v)
    {
        int sum = 0;
        for (auto i : v)
            sum += i;
        return sum;
    }
    void get_path_sum_DFS(TreeNode* node, vector<vector<int>>& result, vector<int>& path, int targetSum)
    {
        if (!node) return;

        path.push_back(node->val);

        cout << "path sum : " << get_sum_in_vector(path) << "\n";

        if (get_sum_in_vector(path) == targetSum && !node->left && !node->right)
            result.push_back(path);
        else
        {
            get_path_sum_DFS(node->left, result, path, targetSum);
            get_path_sum_DFS(node->right, result, path, targetSum);
        }

        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        get_path_sum_DFS(root, result, path, targetSum);
        return result;
    }
};
#endif