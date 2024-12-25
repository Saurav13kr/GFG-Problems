#User function Template for python3

class Solution:
    def setMatrixZeroes(self, mat):
        r = len(mat)
        c= len(mat[0])
        check = False
        
        for i in range(r):
            for j in range(c):
                if mat[i][j] == 0:
                    mat[0][j] = 0
                    if i > 0:
                        mat[i][0] = 0
                    else:
                        check = True
        
        for i in range(1, r):
            for j in range(1, c):
                if mat[0][j] == 0 or mat[i][0] == 0:
                    mat[i][j] = 0
        
        if mat[0][0] == 0:
            for i in range(r):
                mat[i][0] = 0
                
        if check:
            for j in range(c):
                mat[0][j] = 0
        
        return mat


#{ 
 # Driver Code Starts
import sys

# Position this line where user code will be pasted.
if __name__ == "__main__":
    input = sys.stdin.read
    data = input().split()

    idx = 0
    t = int(data[idx])
    idx += 1
    results = []

    for _ in range(t):
        n, m = map(int, data[idx:idx + 2])
        idx += 2
        arr = []
        for i in range(n):
            arr.append(list(map(int, data[idx:idx + m])))
            idx += m

        sol = Solution()
        sol.setMatrixZeroes(arr)

        for row in arr:
            results.append(" ".join(map(str, row)))

        results.append("~")

    sys.stdout.write("\n".join(results) + "\n")

# } Driver Code Ends