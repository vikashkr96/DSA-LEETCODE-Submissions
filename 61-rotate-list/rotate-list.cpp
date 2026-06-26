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

    ListNode* findNthNode(ListNode* head, int n){
        ListNode* temp = head;
        while(n > 1){
            temp = temp->next;
            n--;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL){
            len++;
            tail= tail->next;
        }

        if( k % len == 0) return head;
        k = k % len;

        tail->next = head;

        ListNode* newTail = findNthNode(head, len-k);
        head = newTail->next;
        newTail->next = nullptr;

        return head;
    }
};