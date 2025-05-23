
#User function Template for python3

class Solution:
    def searchMatrix(self, mat, x): 
        def binsrch(mt,idx,k):
            s = 0
            e = len(mt[idx])-1
            while s<=e:
                mid = s+(e-s)//2
                if mt[idx][mid]==k:
                    return True
                elif mt[idx][mid]<k:
                    s = mid+1
                else :
                    e = mid-1
            return False
        
        for i in range(len(mat)):
            if binsrch(mat,i,x):
                return True
        return False
#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    t = int(data[0])
    index = 1
    for _ in range(t):
        r = int(data[index])
        c = int(data[index + 1])
        index += 2
        matrix = []
        for i in range(r):
            row = list(map(int, data[index:index + c]))
            matrix.append(row)
            index += c
        x = int(data[index])
        index += 1
        ob = Solution()
        if ob.searchMatrix(matrix, x):
            print("true")
        else:
            print("false")
        print("~")
# } Driver Code Ends