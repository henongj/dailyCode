//https://leetcode.com/problems/middle-of-the-linked-list/?envType=study-plan&id=programming-skills-i
//876. Middle of the Linked List
#ifndef ___Middle_of_the_Linked_List_876_h___
#define ___Middle_of_the_Linked_List_876_h___
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<sstream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		vector<int> v;
		// save values
		while (head != nullptr) {
			v.push_back(head->val);
			head = head->next;
		}

		// find middle // 0 1 2 ( 3 /2 ) 0 1 2 3 (4/2)
		int middle = v.size() / 2;

		// make linked list middle to end list
		ListNode* result = new ListNode(v[middle]);
		ListNode* temp = result;
		for (int i = middle + 1; i < v.size(); i++) {
			temp->next = new ListNode(v[i]);
			temp = temp->next;
		}



		return result;
	}
};
#endif // ___Middle_of_the_Linked_List_876_h___
