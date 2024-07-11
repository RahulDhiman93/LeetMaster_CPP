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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        ListNode* left = head;
        ListNode* right = head;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        ListNode* temp = NULL;
        
        while(right != NULL) {
            temp = right->next;
            count++;
            if (count % k == 0) {
                Result result = reverse(left, k);
                curr->next = result.first;
                result.last->next = temp;
                curr = result.last;
                left = temp;
                right = temp;
            } else {
                right = right->next;
            }
        }
        return dummy->next;
    }

private:
    struct Result {
        ListNode* first;
        ListNode* last;
    };
    Result reverse(ListNode* head, int k) {
        ListNode* node = head;
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        while(k>0) {
             temp = node->next;
             node->next = prev;
             prev = node;
             node = temp;
             k--;
        }
        return {prev, head};
    }
};