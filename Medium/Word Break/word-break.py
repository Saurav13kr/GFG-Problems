#User function Template for python3

class Solution:
    def wordBreak(self, n, s, dictionary):
        from collections import defaultdict
        wlth=defaultdict(set)
        for w in dictionary:
            wlth[w[-1]].add(len(w))
        m=len(s)
        from functools import lru_cache
        @lru_cache(None)
        def dp(cur=m-1):
            nonlocal dictionary,wlth
            if cur<0:
                return True
            for lth in wlth[s[cur]]:
                if s[cur-lth+1:cur+1] in dictionary and dp(cur-lth):
                    return True
            return False
        return dp()


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	test_case = int(input())

	for _ in range(test_case):
		n = int(input())
		dictionary = [word for word in input().strip().split()]
		s = input().strip()
		ob = Solution()
		res = ob.wordBreak(n, s, dictionary)
		if res:
			print(1)
		else:
			print(0)
# } Driver Code Ends