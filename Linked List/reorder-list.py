# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:       
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """          
        # find the middle node of the list
        fastPtr = slowPtr = head
        while fastPtr and fastPtr.next:
            fastPtr = fastPtr.next
            if fastPtr.next:
                fastPtr = fastPtr.next
                slowPtr = slowPtr.next
        secondHead = slowPtr.next
        slowPtr.next = None
        
        # Reverse the second List
        prev = next = None
        cur = secondHead
        while cur:
            next = cur.next
            cur.next = prev
            prev = cur 
            cur = next
        
        # concatenate two lists
        secondHalf = prev
        firstHalf = head
        tmp = None
        while firstHalf and secondHalf:
            tmp = firstHalf.next
            firstHalf.next = secondHalf
            firstHalf = tmp
            tmp = secondHalf.next
            secondHalf.next = firstHalf
            secondHalf = tmp
        if firstHalf:
            firstHalf.next = None
    
