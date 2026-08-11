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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* curr = head;
        while(curr){
            curr = curr->next;
            size++;
        }

        if(size == n) return head->next;

        int pos = size-n-1;
        curr = head;
        while(pos--){
            curr = curr->next;
        }

        ListNode* node = curr->next;
        curr->next = node->next;
        delete(node);

        return head;
    }
};
