#User function Template for python3

class Solution:
    def removeBrackets(self, s):
        ans = ""
        f = 0
        v = [0] * len(s)
        st = []
        st1, st2, st3 = set(), set(), set()
        
        for i in range(len(s)):
            if s[i] == '(':
                st.append(i)
                v[i] = st[-1]
            elif s[i] == ')':
                v[i] = st[-1]
                st.pop()
            elif (s[i] == '+' or s[i] == '-') and len(st) > 0:
                v[i] = st[-1]
                st1.add(st[-1])
            elif (s[i] == '*' or s[i] == '/') and len(st) > 0:
                v[i] = st[-1]
                st3.add(st[-1])
            elif len(st) > 0:
                v[i] = st[-1]
        
        for i in range(len(s)):
            if s[i] != '*' and s[i] != '/' and s[i] != '-':
                continue
            j = i + 1
            if s[i] == '-':
                while j < len(s) and s[j] == '(':
                    if v[j] in st1:
                        st2.add(j)
                    j += 1
                continue
            j = i + 1
            while j < len(s) and s[j] == '(':
                if v[j] in st1:
                    st2.add(j)
                j += 1
            if s[i] == '/':
                j = i + 1
                while j < len(s) and s[j] == '(':
                    if v[j] in st3:
                        st2.add(j)
                    j += 1
            
            j = i - 1
            while j >= 0 and s[j] == ')':
                if v[j] in st1:
                    st2.add(j)
                j -= 1
        
        for i in range(len(s)):
            if s[i] != ')' and s[i] != '(':
                ans += s[i]
            else:
                if v[i] in st2:
                    ans += s[i]
        
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        Exp = input()

        ob = Solution()
        print(ob.removeBrackets(Exp))


# } Driver Code Ends