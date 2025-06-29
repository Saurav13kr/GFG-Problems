class Solution:
    def splitArray(self, nums, k):
        mn=max(nums)
        mx=sum(nums)
        res=-1
        while(mn<=mx):
            mid=(mn+mx)//2
            cnt=1
            sm=0
            for i in nums:
                if(sm+i<=mid):
                    sm+=i
                else:
                    cnt+=1
                    sm=i
            if(cnt<=k):
                res=mid
                mx=mid-1
            else:
                mn=mid+1
        return mn