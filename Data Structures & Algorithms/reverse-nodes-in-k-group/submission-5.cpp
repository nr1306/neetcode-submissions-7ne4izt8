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
        ListNode* prev = NULL;
        while(head){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    ListNode* findkthNode(ListNode* head, int k){
        while(k>1 && head){
            head = head->next;
            k--;
        }

        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while(temp){
            ListNode* kthNode = findkthNode(temp, k);
            if(kthNode == NULL){
                prevNode->next = temp; // we'll just connect our prevNode with current remaining group
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            reverse(temp);

            if(temp == head){ // it indicates its a first group of list
                head = kthNode;
            }
            else{
                prevNode->next = kthNode;
            }

            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};
