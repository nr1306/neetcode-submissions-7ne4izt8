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
        ListNode* prev = NULL, *curr = head;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

// We are putting 2 pointers one before the left(th) node and one after right(th) node
// Then we are just reversing the subarray and then connecting the reversed list with the 2 pointers
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int pos1 = 1, pos2 = 0; // We are starting pos1 from 1 as we are already on first node 
        ListNode* before = head, *after = head;
        while(pos1 < (left-1) || pos2 < (right-1)){
            if(pos1 < (left-1)){
                before = before->next;
                pos1++;
            }

            if(pos2 < (right-1)){
                after = after->next;
                pos2++;
            }
        }


        ListNode* temp = after->next;
        after->next = NULL;
        cout << after->val << endl;
        if(left == 1){
            head = reverse(before);
            before->next = temp;
        }
        else{
            ListNode* node = before->next;
            cout << before->val;
            before->next = reverse(before->next);
            node->next = temp;
        }

        return head;
    }
};