
//https://leetcode.com/problems/linked-list-in-binary-tree/description/?envType=study-plan&id=programming-skills-ii
//1367. Linked List in Binary Tree
#ifndef ___Linked_List_in_Binary_Tree_1367_h___
#define ___Linked_List_in_Binary_Tree_1367_h___

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


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
	bool dfs(ListNode* head, TreeNode* root) {
		if (head == nullptr)
			return true;
		if (root == nullptr)
			return false;
		if (head->val != root->val)
			return false;
		return dfs(head->next, root->left) || dfs(head->next, root->right);
	}
	bool isSubPath(ListNode* head, TreeNode* root) {
		if (head == nullptr)
			return true;
		if (root == nullptr)
			return false;
		return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
	}
};
#endif // !___Linked_List_in_Binary_Tree_1367_h___
