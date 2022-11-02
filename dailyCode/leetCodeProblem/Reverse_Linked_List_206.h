#ifndef ___Reverse_Linked_List_206_h___
#define ___Reverse_Linked_List_206_h___

//https ://leetcode.com/problems/reverse-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void swap_value_in_node(vector<ListNode*>& v, int idx1, int idx2)
    {
        int save = v[idx1]->val;
        v[idx1]->val = v[idx2]->val;
        v[idx2]->val = save;
    }
    void revserse_list(vector<ListNode*>& v, int idx1, int idx2)
    {
        if (idx1 >= idx2)
            return;
        swap_value_in_node(v, idx1, idx2);
        revserse_list(v, ++idx1, --idx2);
    }

    ListNode* reverseList(ListNode* head) {
        vector<ListNode*> v;
        if (head == nullptr)
            return head;

        v.push_back(head);
        ListNode* next_list = head->next;
        while (1)
        {
            if (next_list == nullptr)
                break;
            else
            {
                v.push_back(next_list);
                next_list = next_list->next;
            }
        }

        int idx1 = 0;
        int idx2 = v.size() - 1;
        cout << v.size();
        revserse_list(v, idx1, idx2);

        return head;
    }
}; 

#endif // !___Reverse_Linked_List_206_h___
