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
        ListNode* curr = new ListNode();
        ListNode* newHead = new ListNode(0,curr);
        int carry = 0;

        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum %= 10;
            curr->val = sum;

            l1 = l1->next;
            l2 = l2->next;

            if(l1 || l2 || carry)
                curr->next = new ListNode();
            
            curr = curr->next;
        }

        while(l1){
            int sum = l1->val + carry;
            carry = sum/10;
            sum %= 10;
            curr->val = sum;

            l1 = l1->next;

// If other list is finished and there is no carry - we can connect
            if(!carry){ 
                curr->next = l1;
                break;
            }

            curr->next = new ListNode();
            curr = curr->next;
        }
        

        while(l2){
            int sum = l2->val + carry;
            carry = sum/10;
            sum %= 10;
            curr->val = sum;

            l2 = l2->next;

            if(!carry){
                curr->next = l2;
                break;
            }

            curr->next = new ListNode();
            curr = curr->next;
        }

        if(carry) curr->val = carry;
        return newHead->next;
    }
};
