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
        ListNode* slow = head, *fast = head;
        if(!slow->next || !slow->next->next) return;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }


        // now the slow pointer is at the middle element
        // will reverse second half of list

        ListNode* middle = slow;
        middle->next = reverse(middle->next);

        ListNode* second = middle->next;
        ListNode* first = head;

        while(middle->next){
            ListNode* node = second->next;
            ListNode* temp = first->next;
            first->next = second;
            second->next = temp;
            first = temp;
            middle->next = node;
            second = node;
        }

    }
};
