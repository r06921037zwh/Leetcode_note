# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head == None or head.next == None:
            return head
        
        dummy = ListNode(-1, head)
        # find the node count
        cnt = 0
        while head:
            head = head.next
            cnt += 1
        
        k = k % cnt 
        # find the last k+1 node
        slowPtr = fastPtr = dummy
        for _ in range(k):
            fastPtr = fastPtr.next
            if fastPtr == None:
                return head
        
        # slowPtr will be the node previous to last kth node
        # fastPtr will be the last node
        while fastPtr.next:
            fastPtr = fastPtr.next
            slowPtr = slowPtr.next
        
        fastPtr.next = dummy.next
        dummy.next = slowPtr.next 
        slowPtr.next = None
        
        return dummy.next
           
