#ifndef ___Maximum_Depth_of_Binary_Tree_104_h___
#define ___Maximum_Depth_of_Binary_Tree_104_h___
#include<utility>
#include<vector>
#include<iostream>
#include<string>
#include<queue>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  class Solution {
  public:
      int findMaxOrder(TreeNode* node, int depth)
      {
          int num = depth;


          TreeNode* next_left = node->left;
          TreeNode* next_right = node->right;
          if (next_left != nullptr)
              depth = max(depth, findMaxOrder(next_left, num + 1));
          if (next_right != nullptr)
              depth = max(depth, findMaxOrder(next_right, num + 1));

          return max(depth, num);
      }
      int maxDepth(TreeNode* root) {
          int depth = 1;
          if (root == nullptr)
              return 0;
          depth = max(depth, findMaxOrder(root, depth));
          return depth;
      }
  };

  class Solution2 {
  public:
      int countDepth(TreeNode* node, int depth)
      {
          if (node == nullptr)
              return depth;
          int left = countDepth(node->left, depth + 1);
          int right = countDepth(node->right, depth + 1);

          return max(left, right);
      }
      int maxDepth(TreeNode* root) {
          int depth = 0;
          if (root == nullptr) return depth;
          return countDepth(root, depth);
      }
  };
#endif // ___Maximum_Depth_of_Binary_Tree_104_h___


