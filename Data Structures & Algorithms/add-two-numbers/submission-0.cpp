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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = l1->val + l2->val;
        int carry = sum > 9 ? 1 : 0;
        ListNode* head = new ListNode(sum%10);
        l1 = l1->next;
        l2 = l2->next;
        ListNode* temp = head;
        
        while(l1 && l2){
            sum = l1->val + l2->val + carry;
            carry = sum > 9 ? 1 : 0;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            sum = l1->val + carry;
            carry = sum > 9 ? 1 : 0;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
            l1 = l1->next;
        }

        while(l2){
            sum = l2->val + carry;
            carry = sum > 9 ? 1 : 0;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
            l2 = l2->next;
        }

        if(carry){
            ListNode* node = new ListNode(1);
            temp->next = node;
        }
        return head;
    }
};
