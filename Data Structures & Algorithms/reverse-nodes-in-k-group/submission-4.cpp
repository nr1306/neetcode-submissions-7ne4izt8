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

    ListNode* findKthNode(ListNode* head, int k){
        while(k > 1 && head){
            head = head->next;
            k--;
        }
        return head;
    }

// What we are doing is we are first finding the first and kth node in a group
// After fining that we are keeping track of our next node, (First ndoe of second group)
// Then we are breaking that link and pointing kth node to nUll seperating out list
// Reversing our list normally then we are checking if our previous head of our list is == head which means it is our first k group it means we have to update our head of our parent list
// If not we'll connect the prevNode we are saving to our updated head which is our kth ndoe (after reversing)
// At each iteration we are connecting our prevNode with our current revered group and breaking link with next group

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        ListNode* nextNode = NULL;

        while(temp){
            ListNode* kthNode = findKthNode(temp,k);
            if(kthNode == NULL){
                prevNode->next = temp;
                break;
            }

            nextNode = kthNode->next;
            kthNode->next = NULL;
            
            reverse(temp);
            if(temp == head){
                head = kthNode; // updating the head of the parent list, coz this is the first k group
            }
            else{
                prevNode->next = kthNode;
            }
            prevNode = temp; // storing the prevNode for 2nd K group
            temp = nextNode; // moving to next k group
        }
        return head;
    }
};
