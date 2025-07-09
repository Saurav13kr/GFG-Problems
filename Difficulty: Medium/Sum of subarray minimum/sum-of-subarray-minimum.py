class Solution:
    def sumSubMins(self, arr):
        n=len(arr)
        res=0
        stack=[]
        
        for i in range(n+1):
            while stack and (i==n or arr[stack[-1]]>arr[i]):
                mid=stack.pop()
                left=stack[-1] if stack else -1
                cnt=(mid-left)*(i-mid)
                res=res+cnt*arr[mid]
            stack.append(i)
        return res