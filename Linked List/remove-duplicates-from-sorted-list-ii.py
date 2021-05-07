# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        
        preHead = ListNode(0, head)
        prevNode = preHead
        while head != None:
            if head.next and head.val == head.next.val:
                while head.next and (head.val == head.next.val):
                    head = head.next
                prevNode.next = head.next
            else:
                prevNode = prevNode.next
            head = head.next
            
        return preHead.next
                               
