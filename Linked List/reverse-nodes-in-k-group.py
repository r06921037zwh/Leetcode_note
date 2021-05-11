# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if head == None or head.next == None:
            return head
        
        dummy = ListNode(-1, head)
        pre = dummy
        start = end = head
        while True:
            # check whether still has k nodes group
            has_k_remain = True
            for _ in range(k-1):
                if end:
                    end = end.next
                else:
                    has_k_remain = False
                    break
            
            # if still has k nodes in group, need to reverse them
            if end and has_k_remain:
                nextStart = end.next
                tmp_pre = start
                tmp_cur = tmp_pre.next
                tmp_next = None
                for _ in range(k-1):
                    tmp_next = tmp_cur.next
                    tmp_cur.next = tmp_pre
                    tmp_pre = tmp_cur
                    tmp_cur = tmp_next
                
                start.next = nextStart 
                pre.next = end
                pre = start
                start = end = nextStart
            # if not, just return the head
            else:
                return dummy.next
                
 
# Recursive Method
