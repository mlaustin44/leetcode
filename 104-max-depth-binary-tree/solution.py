Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        #non-existant node
        if not root:
        	return 0
        #get the left and right depths.  will call recursively until we hit a null node
        left_depth = self.maxDepth(root.left)
        right_depth = self.maxDepth(root.right)
        #return the greater of the two sides
        if left_depth > right_depth:
        	return left_depth + 1
        else:
        	return right_depth + 1