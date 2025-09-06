# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        
        p, q, r = None, head, head.next

        while r:
            temp = r.next
            r.next = q
            q.next = p

            p, q, r = q, r, temp
        
        return q