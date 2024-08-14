#User function Template for python3

class Solution:
    def longestCommonSubstr(self, str1, str2):
        max_len=0
        for i in range(len(str1)):
            for j in range(i,len(str1)):
                s=str1[i:j+1]
                if s in str2:
                    max_len=max(max_len,len(s))
        return max_len 

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        S1 = input().strip()
        S2 = input().strip()
        ob = Solution()
        print(ob.longestCommonSubstr(S1, S2))

# } Driver Code Ends