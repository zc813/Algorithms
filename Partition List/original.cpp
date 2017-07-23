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
        begin.next = head;
        ListNode * ptr1 = head;
        ListNode * ptr2 = &middle;
        ListNode * prev = &begin;
        while (ptr1 != NULL){
            if (ptr1 -> val >= x){
                prev -> next = ptr1 -> next;

                ptr2 -> next = ptr1;
                ptr2 = ptr1;
                ptr2 -> next = NULL;
                
                ptr1 = prev -> next;
            } else {
                prev = ptr1;
                ptr1 = ptr1 -> next;
            }
        }
        prev -> next = middle.next;
        return begin.next;
    }
};
