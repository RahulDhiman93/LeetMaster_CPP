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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode* list1 = l1;
        ListNode* list2 = l2;
        ListNode* resHead= new ListNode();
        ListNode* res=resHead;
        int sum=0, carry=0, add=0;
        while(list1 != NULL || list2 != NULL) {
            int v1 = list1 != NULL ? list1->val : 0;
            int v2 = list2 != NULL ? list2->val : 0;
            sum = v1 + v2 + carry;
            add = sum % 10;
            carry = sum / 10;
            ListNode* node = new ListNode(add);
            res->next = node;
            res = res->next;
            
            if (list1 != NULL) {
                list1 = list1->next;
            }
            if (list2 != NULL) {
                list2 = list2->next;
            }
        }
        if (carry > 0) {
            res->next = new ListNode(carry);
        }
        return resHead->next;
    }
};