
#ifndef ___Leaf-Similar_Trees_872_h___
#define ___Leaf-Similar_Trees_872_h___
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<sstream>
#include<stack>
using namespace std;

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
	void get_leaf_node(TreeNode* root, vector<int>& leafs)
	{
		if (root == nullptr)
			return;
		
		if (root->left == nullptr && root->right == nullptr)
		{
			leafs.push_back(root->val);
			return;
		}
		
		get_leaf_node(root->left, leafs);
		get_leaf_node(root->right, leafs);
	}
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> leafs1;
		vector<int> leafs2;
		get_leaf_node(root1, leafs1);
		get_leaf_node(root2, leafs2);
		for (auto i : leafs1)
			cout << " " << i;
		cout << endl;
		for (auto i : leafs2)
			cout << " " << i;

		// 두 백터가 같은지 (리프 노드들이 똑같게 모였는지) 확인
		if (leafs1.size() == leafs2.size())
		{
			for (int i = 0; i < leafs1.size(); i++)
				if (leafs1[i] != leafs2[i])
					return false;
		}
		else
			return false;
		return true;
	}
};



#endif // ___Leaf-Similar_Trees_872_h___