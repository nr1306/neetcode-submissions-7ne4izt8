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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        while(head){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        // First we'll reach to the middle element and reverse the second part of linkedlist
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* middle = slow;
        middle->next = reverse(middle->next);
       
        ListNode* first = head, *second = middle->next;
        while(middle->next){ // After making the required combo middle becomes last node in the list
            ListNode* temp = second->next;
            second->next = first->next;
            first->next = second;
            first = second->next;
            middle->next = temp;
            second = middle->next;
        }
    }
};
