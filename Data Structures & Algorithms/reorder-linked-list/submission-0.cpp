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
    ListNode* reverse(ListNode* node){
        ListNode* prev = nullptr;
        while(node){
            ListNode* temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* middle = head, *fast = head;
        int size = 0;
        
        while(fast->next && fast->next->next){
            middle = middle->next;
            fast = fast->next->next;
            size++;
        }
       
        ListNode* rev = reverse(middle->next);
        middle->next = rev;

        ListNode* first = head, *second = middle->next;
        while(first != middle){
            middle->next = second->next;
            second->next = first->next;
            first->next = second;
            first = second->next;
            second = middle->next;
        }
    }
};
