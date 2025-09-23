class Solution:
    def reverseQueue(self, q):
        l=len(q)
        for i in range(0,(l+1)//2):
            q[i],q[l-1-i]=q[l-1-i],q[i]