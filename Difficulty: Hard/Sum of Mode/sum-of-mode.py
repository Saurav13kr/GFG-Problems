import heapq
class Solution:
    def sumOfModes(self, arr, k):
        # code here
        res=0
        count={}
        hp=[]
        for i,j in enumerate(arr):
            count[j]=count.get(j,0)+1
            heapq.heappush(hp,(-count[j],j,))
            if i-k>=0:
                count[arr[i-k]]-=1
            if i>=k-1:
                while -hp[0][0]!=count[hp[0][1]]:
                    heapq.heappop(hp)
                res+=hp[0][1]
        return res

