class Solution:
    def minDifference(self, arr):
        
        for i in range(len(arr)):
            temp=arr[i].split(":")
            sum1=int(temp[0])*3600+int(temp[1])*60+int(temp[2])
            
            arr[i]=sum1
  
        arr.sort()
        
        min1=86400
  
        for i in range(0,len(arr)-1):
            if arr[i+1]-arr[i]<min1:
                min1=arr[i+1]-arr[i]
        min1=min(min1,(86400-arr[-1])+arr[0])
        return min1