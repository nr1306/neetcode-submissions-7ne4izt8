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
    ListNode* reverse(ListNode* head, ListNode* prev, int k){
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
        if(k == 1) return head;

        ListNode* curr = nullptr; // will keep track of node before localHead
        ListNode* node = head; // will be at node after kth group
        
        while(node){
            int count = 0;
    // This will represent localHead of every k group
            ListNode* localHead = new ListNode();
    // if its first k group, localHead will be head of list
            if(!curr) localHead = head;
            else localHead = node;

    // Every k group we are keeping one pointer at ndoe before localHead
    // And one node after kth node in that group
            while(node && count<k){
                node = node->next;
                count++;
            }
            if(count < k) break;
    // 'node' is also used as a prev pointer utilized while reversing the list
            ListNode* newLocalHead = reverse(localHead,node,k);
    
    // If its the first k group we'll update the curr with localHead which is reversed and went to kth place from start 
    // Also updated the head of our list
            if(!curr){
                head = newLocalHead;
            } 
    // connecting the list with the pointer ahead of localHead
            else curr->next = newLocalHead;
            curr = localHead; // updating the curr everytime we reverse a group
        }
        return head;
    }
};
