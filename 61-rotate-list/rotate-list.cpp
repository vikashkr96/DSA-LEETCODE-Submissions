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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL || k == 0)
            return head;

        // find length and tail
        ListNode* tail = head;
        int len = 1;

        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }

        // reduce k
        k = k % len;

        if(k == 0)
            return head;

        // make circular
        tail->next = head;


        // find new tail
        int steps = len - k;

        ListNode* newTail = tail;

        while(steps--){
            newTail = newTail->next;
        }

        // new head is after new tail
        ListNode* newHead = newTail->next;

        // break circle
        newTail->next = NULL;

        return newHead;
    }
};