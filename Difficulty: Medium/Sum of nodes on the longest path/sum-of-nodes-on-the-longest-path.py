'''
class Node:
    def __init__(self, val):
        self.data=val
        self.left=None
        self.right=None
'''
class Solution:
    def sumOfLongRootToLeafPath(self, root):
        maxlensum=0
        maxlen=0
        def traverse(node,l,s):
            nonlocal maxlen
            nonlocal maxlensum
            if node is None:
                return 
            if node:
                s+=node.data
            traverse(node.left,l+1,s)
            traverse(node.right,l+1,s)
            
            if l>maxlen:
                maxlen=l
                maxlensum=s
            elif l==maxlen:
                maxlensum=max(maxlensum,s)
            return
        
        traverse(root,0,0)
        return maxlensum