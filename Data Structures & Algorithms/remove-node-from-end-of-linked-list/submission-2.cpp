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

        if(size == 1){
            head = head->next;
            return head;
        }
        if(size == n){
            ListNode* node = head;
            head = head->next;
            delete(node);
            return head;
        }

        int ind = size-n;
        curr = head;
        ListNode* prev = head;

        while(ind && curr){
            ListNode* temp = curr->next;
            prev = curr;
            curr = temp;
            ind--;
        }

        prev->next = curr->next;
        delete(curr);
        return head;        
    }
};
