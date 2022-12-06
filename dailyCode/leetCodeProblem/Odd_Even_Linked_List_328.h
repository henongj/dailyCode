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

		//홀수 노드를 순서대로 모두 가져오고, 짝수는 순서대로 모두 뒤로 이동시켜야한다
		
		ListNode* odd = head; // 홀
		ListNode* even = head->next; // 짝
		
		
		ListNode* evenHead = even; // 접합부
		
		while (even != nullptr && even->next != nullptr) {
			odd->next = even->next; // 홀수 노드끼리 연결한다
			odd = odd->next;  // 다음 홀수 노드로 이동한다
			
			even->next = odd->next; // 짝수 노드끼리 연결한다
			even = even->next; // 다음 짝수 노드로 이동한다
		}
		/*
		예시
		1 2 3 4 5 6 7 이었다면
		1 3 5 7(odd = 7 가리키는 중)
		2 4 6 (even = 6 가리키는 중)
		evenhead는 2를 가리키고 있다
		
		여기서 7번 노드를 2와 연결
		*/
		
		odd->next = evenHead;
		
		
		return head;
		
	}
};

#endif // !___Odd_Even_Linked_List_328_h___
