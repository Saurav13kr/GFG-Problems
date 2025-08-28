class Solution:
    def maxOnes(self, arr, k):
        count_0 = 0
        l,r = 0,0
        max_len = 0
        
        while r < len(arr):
            if arr[r] == 0:
                count_0 +=1
    
            if count_0 > k:
                if arr[l] == 0:
                    count_0 -=1
                l +=1
            
            
            max_len = max(max_len, r-l+1)
            r+=1
        
        return max_len