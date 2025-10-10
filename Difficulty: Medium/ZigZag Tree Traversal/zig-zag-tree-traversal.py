from queue import Queue
class Solution:
    def zigZagTraversal(self, root):
        if not root:
            return root
        q=Queue()
        q.put(root)
        res=[]
        level=0
        while not q.empty():
            n=q.qsize()
            temp=[]
            level+=1
            for i in range(n):
                node=q.get()
                temp.append(node.data)
                if node.left:
                    q.put(node.left)
                if node.right:
                    q.put(node.right)
            if level%2==0:
                res.extend(temp[::-1])
            else:
                res.extend(temp)
        return res