/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> smap;
        ListNode* node = head;
        while(node != NULL) {
            if (smap.contains(node->next)) {
                return true;
            }
            smap.insert(node->next);
            node = node->next;
        }
        return false;
    }
};