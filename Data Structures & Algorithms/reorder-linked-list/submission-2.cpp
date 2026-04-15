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
    ListNode* middleElement(ListNode* head){
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow; // middle element of list
    }

    ListNode* reverse(ListNode* node){
        ListNode* prev = NULL;
        while(node){
            ListNode* temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        // First we'll reach at middle of linked list
        // We'll reverse the second half of the list
        // Then we'll take one element at a time and attach it to the element of first half
        // OBSERVE: After attaching second half ele to first half, at last middle element will become the last element in the list
        ListNode* res = head;

        ListNode* middle = middleElement(head);
        middle->next = reverse(middle->next);

// We'll iterate till middle ele becomes the last ele
        while(middle->next){
            ListNode* temp1 = middle->next->next;
            ListNode* temp2 = head->next;
            head->next = middle->next;
            middle->next->next = temp2;
            middle->next = temp1;
            head = temp2;
        }

        head = res;
    }
};
