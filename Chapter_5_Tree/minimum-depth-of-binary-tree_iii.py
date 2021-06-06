# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: TreeNode) -> int: 
        if not root:
            return 0
        return self.bfs(root)
        
    def bfs(self, node):
        if not node.left and not node.right:
            return 1
        left_min = right_min = float('inf')
        if node.left:
            left_min = self.bfs(node.left)
        if node.right:
            right_min = self.bfs(node.right)
        return min(left_min, right_min) + 1
