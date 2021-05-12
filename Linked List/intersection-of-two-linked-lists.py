# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None
        lenA = 1
        curA, curB = headA, headB
        while curA and curA.next:
            curA = curA.next
            lenA += 1
            
        lenB = 1
        while curB and curB.next:
            curB = curB.next
            lenB += 1
            
        if lenA > lenB:
            diff = lenA - lenB
            for _ in range(diff):
                headA = headA.next
        else:
            diff = lenB - lenA
            for _ in range(diff):
                headB = headB.next
        
        while headA and headB and headA != headB:
            headA = headA.next
            headB = headB.next
        
        return headA

# Hash method
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None
        
        hashset = set()
        while headA:
            hashset.add(headA)
            headA = headA.next
            
        has_intersection = False
        while headB:
            if headB not in hashset:
                headB = headB.next
            else:
                has_intersection = True
                break
        
        if not has_intersection:
            return None
        
        return headB
            
