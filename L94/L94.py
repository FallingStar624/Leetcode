from typing import List, Optional
from collections import deque


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.ans = []

    def inorderTraversalHelp(self, node: Optional[TreeNode]) -> None:
        if not node:
            return
        self.inorderTraversalHelp(node.left)
        self.ans.append(node.val)
        self.inorderTraversalHelp(node.right)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.inorderTraversalHelp(root)
        return self.ans

