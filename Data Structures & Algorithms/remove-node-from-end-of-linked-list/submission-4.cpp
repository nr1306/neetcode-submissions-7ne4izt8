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
        ListNode* curr = head;
        int size = 0;
        while(curr) {
            curr = curr->next;
            size++;
        }
        cout << size;
        if(size == n) return head->next;

        int pos = size-n;
        curr = head;
        ListNode* prev = head;
        while(pos != 0 && curr){
            prev = curr;
            curr = curr->next;
            pos--;
        }
    
        prev->next = curr->next;
        delete(curr);
        return head;
    }
};
