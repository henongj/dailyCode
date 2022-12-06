//https://leetcode.com/problems/odd-even-linked-list/
//328. Odd Even Linked List
#ifndef ___Odd_Even_Linked_List_328_h___
#define ___Odd_Even_Linked_List_328_h___


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == nullptr) 
			return head;

		//Ȧ�� ��带 ������� ��� ��������, ¦���� ������� ��� �ڷ� �̵����Ѿ��Ѵ�
		
		ListNode* odd = head; // Ȧ
		ListNode* even = head->next; // ¦
		
		
		ListNode* evenHead = even; // ���պ�
		
		while (even != nullptr && even->next != nullptr) {
			odd->next = even->next; // Ȧ�� ��峢�� �����Ѵ�
			odd = odd->next;  // ���� Ȧ�� ���� �̵��Ѵ�
			
			even->next = odd->next; // ¦�� ��峢�� �����Ѵ�
			even = even->next; // ���� ¦�� ���� �̵��Ѵ�
		}
		/*
		����
		1 2 3 4 5 6 7 �̾��ٸ�
		1 3 5 7(odd = 7 ����Ű�� ��)
		2 4 6 (even = 6 ����Ű�� ��)
		evenhead�� 2�� ����Ű�� �ִ�
		
		���⼭ 7�� ��带 2�� ����
		*/
		
		odd->next = evenHead;
		
		
		return head;
		
	}
};

#endif // !___Odd_Even_Linked_List_328_h___
