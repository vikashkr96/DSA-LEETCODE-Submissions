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

    int sizeLL(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp != nullptr){
            count+= 1;
            temp = temp->next;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m = sizeLL(head);

        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* prev = temp;
        
        for(int i = 0; i < m-n; i++){
            prev = prev->next;
        }

        prev->next = prev->next->next;
        return temp->next;
    }
};