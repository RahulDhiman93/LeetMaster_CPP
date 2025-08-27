# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode(0)
        l3 = ListNode(0)
        head = l3
        carry = 0

        while l1 and l2:
            val = l1.val + l2.val + carry
            carry = int(val / 10)
            val = int(val % 10)
            

            node = ListNode(val)
            l3.next = node
            l3 = l3.next

            l1 = l1.next
            l2 = l2.next
        
        while l1:
            val = l1.val + carry
            carry = int(val / 10)
            val = int(val % 10)
            

            node = ListNode(val)
            l3.next = node
            l3 = l3.next

            l1 = l1.next
        
        while l2:
            val = l2.val + carry
            carry = int(val / 10)
            val = int(val % 10)
            

            node = ListNode(val)
            l3.next = node
            l3 = l3.next

            l2 = l2.next
        
        if carry:
            node = ListNode(carry)
            l3.next = node
            l3 = l3.next
        
        return head.next

        
