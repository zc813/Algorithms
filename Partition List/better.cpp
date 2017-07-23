/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode begin(0), middle(0);
        ListNode * ptr1 = &begin;
        ListNode * ptr2 = &middle;
        while (head != NULL){
            if (head -> val < x)
                ptr1 = ptr1 -> next = head;
            else
                ptr2 = ptr2 -> next = head;
            head = head -> next;
        }
        ptr1 -> next = middle.next;
        ptr2 -> next = NULL;
        return begin.next;
    }
};
