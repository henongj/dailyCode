
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// ___Populating_Next_Right_Pointers_in_Each_Node_116_h___
#ifndef ___Populating_Next_Right_Pointers_in_Each_Node_116_h___
#define ___Populating_Next_Right_Pointers_in_Each_Node_116_h___
#include<vector>
#include<iostream>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        // node->val , (next) ? next->val , '#' || 
        // node -> left 순회
        // node -> right  next로 가버림
        if (!root)
            return;

        if (root->left)
            root->left->next = root->right;
        if (root->right && root->next)
            root->right->next = root->next->left;

        connect(root->left);
        connect(root->right);

        return root;
    }
};
#endif
