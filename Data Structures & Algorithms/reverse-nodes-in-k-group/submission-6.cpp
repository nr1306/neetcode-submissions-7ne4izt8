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
    ListNode* reverse(ListNode* head, int k){
        ListNode* prev = NULL;
        while(head && k){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;

            k--;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy1 = new ListNode(0, head);
        ListNode* dummy2 = head;

// Doint the first iteration of reversing k groups first outside
// To get the updated head of result list
        int pos = k;
        while(dummy2 && pos--){
            dummy2 = dummy2->next;
        }
        if(pos > 0) return head;

        ListNode* node = reverse(head, k);
        dummy1->next = node;
        head->next = dummy2;
        dummy1 = head;

        head = node; // updating the head of list

        while(dummy2){
            int pos = k;
            while(dummy2 && pos--){
                dummy2 = dummy2->next;
            }
        // our group has less than k elements
            if(pos > 0) return head; // returning head

            ListNode* intermHead = dummy1->next;
            ListNode* node = reverse(intermHead, k);
            dummy1->next = node;
            intermHead->next = dummy2;
            dummy1 = intermHead;
        }

        return head;
    }
};
