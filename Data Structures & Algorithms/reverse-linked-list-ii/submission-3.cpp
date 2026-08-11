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
    ListNode* reverse(ListNode* head, int count){
        ListNode* prev = NULL;
        while(head && count--){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* beforeLeft = head;
        ListNode* afterRight = head;
        int count = right-left+1;

        while(right--){
            afterRight = afterRight->next;
        }

        if(left == 1){
            ListNode* newHead = reverse(head, count);
            head->next = afterRight;
            return newHead;
        }

        left--;
        while(left > 1){
            beforeLeft = beforeLeft->next;
            left--;
        }

        ListNode* node = beforeLeft->next;
        beforeLeft->next = reverse(node, count);
        node->next = afterRight;
        return head;
    }
};