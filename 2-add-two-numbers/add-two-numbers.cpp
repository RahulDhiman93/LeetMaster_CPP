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
        ListNode* list1 = l1;
        ListNode* list2 = l2;
        ListNode* resHead=NULL;
        ListNode* res=NULL;
        int sum=0, carry=0, add=0;
        while(list1 != NULL && list2 != NULL) {
            sum = list1->val + list2->val + carry;
            add = sum % 10;
            carry = sum / 10;
            ListNode* node = new ListNode(add);
            if (resHead == NULL) {
                resHead = node;
                res = resHead;
            } else {
                res->next = node;
                res = res->next;
            }
            list1 = list1->next;
            list2 = list2->next;
        }
        while(list1 != NULL) {
            sum = list1->val + carry;
            add = sum % 10;
            carry = sum / 10;
            ListNode* node = new ListNode(add);
            if (resHead == NULL) {
                resHead = node;
                res = resHead;
            } else {
                res->next = node;
                res = res->next;
            }
            list1 = list1->next;
        }
        while(list2 != NULL) {
            sum = list2->val + carry;
            add = sum % 10;
            carry = sum / 10;
            ListNode* node = new ListNode(add);
            if (resHead == NULL) {
                resHead = node;
                res = resHead;
            } else {
                res->next = node;
                res = res->next;
            }
            list2 = list2->next;
        }
        if (carry > 0) {
            ListNode* node = new ListNode(carry);
            res->next = node;
            res = res->next;
        }
        return resHead;
    }
};