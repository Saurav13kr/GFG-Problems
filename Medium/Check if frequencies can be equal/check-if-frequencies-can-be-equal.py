#User function Template for python3
class Solution:
    def sameFreq(self, s):
        # code here
        S=set(s)
        l={}
        for i in S:
            
            l[i]=s.count(i)
            
        freq_count = {}
        for count in l.values():
            if count in freq_count:
                freq_count[count] += 1
            else:
                freq_count[count] = 1
        if len(freq_count) == 1:
                return True
        if len(freq_count) == 2:
                max_freq = max(freq_count.keys())
                min_freq = min(freq_count.keys())
                if (min_freq == 1 and freq_count[min_freq] == 1) or (max_freq - min_freq == 1 and freq_count[max_freq] == 1):
                    return True        
        return False  

if __name__ == "__main__":
	T=int(input())

	for _ in range(T):
		s = input()
		ob = Solution()
		answer = ob.sameFreq(s)
		if answer:
			print(1)
		else:
			print(0)

# } Driver Code Ends
