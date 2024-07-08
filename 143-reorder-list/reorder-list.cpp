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
    void reorderList(ListNode* head) {
        if (head->next == NULL) {
            return;
        }

        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;

        while(fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;

        ListNode* l1 = head;
        ListNode* l2 = reverseList(slow);

        combine(l1, l2);
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr->next;
        
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }

    void combine(ListNode* l1, ListNode* l2) {
        while(l1 != NULL) {
            ListNode* l1Next = l1->next;
            ListNode* l2Next = l2->next;

            l1->next = l2;
            if(l1Next == NULL) {
                break;
            }
            l2->next = l1Next;

            l1=l1Next;
            l2=l2Next;
        }
    }
};