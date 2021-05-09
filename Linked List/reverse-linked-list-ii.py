# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        if head == None or head.next == None or left == right:
            return head
        
        # locate preReverse node as the node previous to the left
        dummy = ListNode(-1, head)
        preReverse = dummy
        for _ in range(left - 1):
            preReverse = preReverse.next

        # reverse the assigned region
        pre = preReverse.next
        cur = pre.next
        tmp = None
        for _ in range(right-left):
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp
        
        # concatenate two sides
        preReverse.next.next = cur
        preReverse.next = pre
        
        return dummy.next
  
