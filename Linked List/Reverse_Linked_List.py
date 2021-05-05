# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        
        prevNode = None
        curNode = head
        while curNode:
            nextNode = curNode.next
            curNode.next = prevNode
            prevNode = curNode
            curNode = nextNode
        
        return prevNode
 
'''
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        new_head = self.reverseRecursive(head)
        return new_head
        
        
    def reverseRecursive(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        
        new_head = self.reverseRecursive(head.next)
        
        cur = new_head
        while cur.next:
            cur = cur.next
        cur.next = head
        head.next = None
        
        return new_head
'''
'''
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        
        preHead = ListNode()
        preHead.next = head
        
        prev = head
        cur = head.next
        while cur:
            prev.next = cur.next
            cur.next = preHead.next
            
            # new setting
            preHead.next = cur
            cur = prev.next
        
        return preHead.next
 '''      
        
