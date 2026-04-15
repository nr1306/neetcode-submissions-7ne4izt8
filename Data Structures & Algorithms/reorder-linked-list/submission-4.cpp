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
        ListNode *prev = NULL;

        while(head){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* fast = head, *slow = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* middle = slow;
        middle->next = reverse(middle->next);
        ListNode* first = head, *second = middle->next;

        while(middle->next){
            ListNode* temp = first->next;
            first->next = second;
            middle->next = second->next;
            second->next = temp;
            second = middle->next;
            first = temp;
        }
    }
};
