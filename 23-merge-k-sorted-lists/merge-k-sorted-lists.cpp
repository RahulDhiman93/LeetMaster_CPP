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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> sa;
        for(int i=0;i<lists.size();++i) {
            ListNode* node = lists[i];
            while(node != NULL) {
                sa.push_back(node->val);
                node = node->next;
            }
        }
        sort(sa.begin(), sa.end());
        
        ListNode* head = new ListNode();
        ListNode* node = head;
        for(int i=0;i<sa.size();++i) {
            node->next = new ListNode(sa[i]);
            node = node->next;
        }
        return head->next;
    }
};