# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        result, stack = [], []
        
        index = 0
        while head:
            result.append(0)
            while len(stack) > 0 and head.val > stack[-1][1]:
                pop_index, _ = stack.pop(-1)
                result[pop_index] = head.val
                
            stack.append([index, head.val])
            head = head.next
            index += 1
        
        return result
            
