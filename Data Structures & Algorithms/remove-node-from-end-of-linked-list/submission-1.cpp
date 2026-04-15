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
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            size++;
        }
        if(n == size){
            ListNode* node = head;
            head = head->next;
            delete node;
            return head;
        }

        ListNode* prev = nullptr;
        temp = head;
        while(size > n){
            prev = temp;
            temp = temp->next;
            size--;
        }
        if(prev)
            prev->next = temp->next;
        delete temp;
        return head;
    }
};
