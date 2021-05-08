# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        toCurPos = 0
        toNextPos = 0
        curSumHead = curSum = ListNode(0, None)
        
        while l1 or l2:
            if l1 and l2:
                temp_sum = l1.val + l2.val + toNextPos 
                l1 = l1.next
                l2 = l2.next
            elif l1:
                temp_sum = l1.val + toNextPos
                l1 = l1.next
            elif l2:    
                temp_sum = l2.val + toNextPos
                l2 = l2.next
            toNextPos = temp_sum // 10
            toCurPos = temp_sum - 10 * toNextPos
            curSum.val = toCurPos
            curSum.next = curSum.next
            
        curSum.next = ListNode(toNextPos, None)
        return curSumHead
                
        
