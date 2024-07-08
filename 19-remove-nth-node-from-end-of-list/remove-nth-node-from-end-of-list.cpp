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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode temp = ListNode(0, head);
        ListNode* tempP = &temp;
        ListNode* left = tempP;
        ListNode* right = head;
        
        int i=0;
        while(i<n && right != NULL) {
            right = right->next;
            i++;
        }

        while(right != NULL) {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;

        return tempP->next;
    }
};