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
    int findSize(ListNode* head){
        ListNode* slow = head, *fast = head;
        int size = 0;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            size++;
        }
        // OBSERVE: length of list is even
        // if(fast) size *= 2;
        // OBSERVE: length of list is odd
        // else if(fast->next) size = size*2 +1;

        return !fast ? size*2 : size*2+1;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = findSize(head);
        int pos = size-n-1; // To reach the one pos behind the node we wanna remove
        if(pos == -1){
            head = head->next;
            return head;
        }

        ListNode* prev = head;
        while(pos){
            pos--;
            prev = prev->next;
        }

        ListNode* temp = prev->next;
        prev->next = temp->next;
        delete(temp);
        return head;
    }
};
