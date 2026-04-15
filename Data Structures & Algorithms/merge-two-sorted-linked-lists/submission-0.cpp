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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)  return list2;
        if(!list2)  return list1;

        int val = min(list1->val, list2->val);
        if(list1->val <= list2->val) list1 = list1->next;
        else list2 = list2->next;
        
        ListNode* head = new ListNode(val);
        ListNode* temp = head;

        while(list1 && list2){
            cout << temp->val << " ";
            val = min(list1->val, list2->val);
            if(list1->val <= list2->val) list1 = list1->next;
            else list2 = list2->next;

            ListNode* node = new ListNode(val);
            temp->next = node;
            temp = temp->next;
        }

        if(!list1)  temp->next = list2;
        if(!list2)  temp->next = list1;
        
        return head;
    }
};
