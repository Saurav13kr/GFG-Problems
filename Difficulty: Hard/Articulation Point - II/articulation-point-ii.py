
class Solution:

    def articulationPoints(self, V, edges):
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        time = [-1] * V
        low = [-1] * V
        critical = [False] * V
        timer = 0

        def dfs(node, parent):
            nonlocal timer
            time[node] = low[node] = timer
            timer += 1
            children = 0

            for nbr in adj[node]:
                if nbr == parent:
                    continue

                if low[nbr] == -1:
                    dfs(nbr, node)
                    children += 1
                    low[node] = min(low[node], low[nbr])
                    if low[nbr] >= time[node] and parent != -1:
                        critical[node] = True
                else:
                    low[node] = min(low[node], time[nbr])

            if children > 1 and parent == -1:
                critical[node] = True

        for i in range(V):
            if low[i] == -1:
                dfs(i, -1)

        ans = [i for i, val in enumerate(critical) if val]
        if not ans:
            return [-1]
        return sorted(ans)

#{ 
 # Driver Code Starts
import sys

sys.setrecursionlimit(int(1e7))


def main():
    tc = int(input())
    for _ in range(tc):
        V = int(input())
        E = int(input())
        edges = []
        for _ in range(E):
            u, v = map(int, input().split())
            edges.append([u, v])
        obj = Solution()
        ans = obj.articulationPoints(V, edges)
        ans.sort()
        print(" ".join(map(str, ans)))
        print("~")


if __name__ == "__main__":
    main()
# } Driver Code Ends