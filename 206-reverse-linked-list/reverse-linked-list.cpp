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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = NULL;
        ListNode* q = head;
        ListNode* r = NULL;

        while(q != NULL) {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }

        return p;
    }
};