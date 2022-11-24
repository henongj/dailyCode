

//https://leetcode.com/problems/n-ary-tree-preorder-traversal/?envType=study-plan&id=programming-skills-i
//589. N-ary Tree Preorder Traversal
#ifndef ___N-ary_Tree_Preorder_Traversal_589_h___
#define ___N-ary_Tree_Preorder_Traversal_589_h___
#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};



class Solution {
public:
    void DFS(Node* node, vector<int>& result)
    {
        if (node == nullptr)
            return;

        result.push_back(node->val);

        for (auto child : node->children)
            DFS(child, result);
    }
    vector<int> preorder(Node* root) {
        vector<int> result;
        DFS(root, result);
        return result;
    }
};


/*
testcase
[1,null,3,2,4,null,5,6]
[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
*/

#endif // ___N-ary_Tree_Preorder_Traversal_589_h___

