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
        int carry = 0;
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        ListNode* prev = curr;

        while(node1 && node2){
            int sum = node1->val + node2->val + carry;
            if(sum >= 10) carry = 1;
            else carry = 0;

            curr->val = sum%10;
            ListNode* temp = new ListNode(0);
            curr->next = temp;

            prev = curr;
            curr = curr->next;
            node1 = node1->next;
            node2 = node2->next;
        }

        while(node1){
            int sum = node1->val + carry;
            if(sum >= 10) carry = 1;
            else carry = 0;

            curr->val = sum%10;
            ListNode* temp = new ListNode(0);
            curr->next = temp;

            prev = curr;
            curr = curr->next;
            node1 = node1->next;
        }  

        while(node2){
            int sum = node2->val + carry;
            if(sum >= 10) carry = 1;
            else carry = 0;

            curr->val = sum%10;
            ListNode* temp = new ListNode(0);
            curr->next = temp;

            prev = curr;
            curr = curr->next;
            node2 = node2->next;
        } 
        cout << curr->val;

        if(carry == 1) curr->val = carry;
        else prev->next = nullptr;
        return head;
    }
};
