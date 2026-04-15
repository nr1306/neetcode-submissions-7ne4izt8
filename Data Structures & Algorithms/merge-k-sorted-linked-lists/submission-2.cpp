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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        

        while(l1 && l2 && l2->val < l1->val){
            ListNode* temp = l2->next;
            l2->next = l1;
            l1 = l2;
            l2 = temp;
        }

        ListNode* res = l1; // updated l1 list with l2 small elements in the beginning

        ListNode* prev = l1;
        while(l1 && l2){
            if(l1->val <= l2->val){
                prev = l1;
                l1 = l1->next;
            }
            else{
                ListNode* node = l2->next;
                prev->next = l2;
                l2->next = l1;
                prev = l2;
                l2 = node;
            }
        }

        if(l2){
            prev->next = l2;
        }

        return res;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        ListNode* l1 = lists[0];
        for(int i=1; i<lists.size(); i++){
            ListNode* l2 = lists[i];
            l1 = mergeTwoLists(l1, l2);
            ListNode* temp = l1;
            while(temp){
                cout << temp->val << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        return l1;
    }
};
