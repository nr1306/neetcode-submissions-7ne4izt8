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
        if(!list1) return list2;
        if(!list2) return list1;

    // we are combining the lists in list1 only
    // If the initial element is bigger than elements of list2 so we'll first update the head of list1
        while(list2 && list1->val > list2->val){
            ListNode* temp = list2->next;
            list2->next = list1;
            list1 = list2;
            list2 = temp;
        }

    // Then we'll iterate on both the lists and keep on adding the smaller element form list2
        ListNode* curr = list1, *prev = list1;
        while(curr && list2){
            if(curr->val <= list2->val){
                prev = curr;
                curr = curr->next;
            } 
            else{
                ListNode* temp = list2->next;
                prev->next = list2;
                list2->next = curr;
                prev = list2;
                list2 = temp;
            }
        }

        if(list2) prev->next = list2;

        return list1;
    }
};
