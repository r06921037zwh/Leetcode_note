# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        if not head:
            return None
        
        cur = dummy = ListNode(-1, head)
        while cur:
            if cur.next and cur.next.val == val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        
        return dummy.next
  
# Recursive Method
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        if not head:
            return None
        
        if head.val == val:
            return self.removeElements(head.next, val)
        else:
            head.next = self.removeElements(head.next, val)
            return head
        
            
