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
        self.mindepth = float('inf')
        self.bfs(root, 1)
        return self.mindepth
        
    def bfs(self, node, depth):
        if not node.left and not node.right:
            self.mindepth = min(self.mindepth, depth)
            return 
        
        if node.left:
            self.bfs(node.left, depth+1)
        if node.right:
            self.bfs(node.right, depth+1)
                    
