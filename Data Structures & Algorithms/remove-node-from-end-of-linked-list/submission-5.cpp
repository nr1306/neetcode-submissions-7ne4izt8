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

        int ind = size-n;
        if(ind == 0) return head->next;
        
        curr = head;
        ListNode* prev = head;
        while(ind > 0){
            prev = curr;
            curr = curr->next;
            ind--;
        }
        prev->next = curr->next;
        delete(curr);
        return head;
    }
};
