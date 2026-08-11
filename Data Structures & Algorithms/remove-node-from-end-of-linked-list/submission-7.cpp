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
        ListNode* dummy = new ListNode(0, head);
        // dummy node pointing to head

        ListNode* left = dummy;
        ListNode* right = head;

// will move right pointer n steps ahead to maintain gap of n steps between left and right

        while(n--) right = right->next;

// Now will move left pointer along with right until it reach end of list
        while(right){
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return dummy->next; // returning head
        
    }
};
