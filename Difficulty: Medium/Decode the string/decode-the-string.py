
class Solution:
    def decodedString(self, s):
        n = len(s)
        # stack = [3,'[', b, 2, '[', c, a]
        stack = []
        ans = ""
        for i in s:
            if i != ']':
                stack.append(i)
            else:
                while stack[-1] != '[':
                    ans = stack.pop() + ans
                stack.pop()
                number = ""
                while stack and stack[-1].isdigit():
                    number = stack.pop() + number
                number = int(number)
                ans = ans * number
                stack.append(ans)
                ans = ""
        return "".join(stack)
        
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()

        ob = Solution()
        print(ob.decodedString(s))
        print("~")

# } Driver Code Ends