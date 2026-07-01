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

    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode* start = head;
        ListNode* middle = findMiddle(head);
        ListNode* rev = reverseLL(middle->next);
        middle->next = nullptr;
        int maximum = 0;
        while(rev != nullptr && start != nullptr){
            int temp = start->val + rev->val;
            maximum = max(maximum, temp);
            start = start->next;
            rev = rev->next;
        }
        return maximum;
    }
};