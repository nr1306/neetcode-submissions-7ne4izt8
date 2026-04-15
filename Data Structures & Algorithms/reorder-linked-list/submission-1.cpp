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
        ListNode* prev = nullptr, *curr = head;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        // First we will find the middle point of the list
        // Then we will reverse the second half of list
        // Then will keep taking the element from second half and appending it to the first half
        // Will keep on doing until middle element comes at last position

        ListNode* middle = head, *fast = head; // here middle pointer will behave as a slow ppinter
        while(fast && fast->next){
            fast = fast->next->next;
            middle = middle->next;
        }

        ListNode* second = reverse(middle->next); // first node of second half of list
        middle->next = second;
        ListNode* first = head; 

    // until middle node becomes last node
        while(middle->next){
            ListNode* temp = first->next;
            middle->next = middle->next->next; // storing the second->next
            first->next = second;
            second->next = temp;
            first = temp;
            second = middle->next;
        }
    }
};
