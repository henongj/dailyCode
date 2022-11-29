
//https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/?envType=study-plan&id=programming-skills-i
//1290. Convert Binary Number in a Linked List to Integer
#ifndef ___Convert_Binary_Number_in_a_Linke_List_to_Integer_1290_h___
#define ___Convert_Binary_Number_in_a_Linke_List_to_Integer_1290_h___

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
	int getDecimalValue(ListNode* head) {
		int sum = 0;
		ListNode* p = head;

		while (p != nullptr) {

			sum = sum << 1;
			if (p->val) {
				sum++;
			}
			p = p->next;
		}

		return sum;
	}
};

#endif // ___Convert_Binary_Number_in_a_Linke_List_to_Integer_1290_h___