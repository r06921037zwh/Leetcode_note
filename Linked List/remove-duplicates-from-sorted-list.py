# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        
        curNode = head
        while curNode != None and curNode.next != None:
            if curNode.val == curNode.next.val:
                curNode.next = curNode.next.next
            else:
                curNode = curNode.next
                
        return head
                
