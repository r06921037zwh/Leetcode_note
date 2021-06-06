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
        depth = 1
        Q = deque([root])
        
        while len(Q) != 0:
            for _ in range(len(Q)):
                node = Q.popleft()
                if not node.left and not node.right:
                    return depth
                
                if node.left:
                    Q.append(node.left)
                if node.right:
                    Q.append(node.right)
                    
            depth += 1
                    
