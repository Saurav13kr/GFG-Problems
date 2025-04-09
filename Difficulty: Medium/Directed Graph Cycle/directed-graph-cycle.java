//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while (tc-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();
            int[][] edges = new int[E][2];
            for (int i = 0; i < E; i++) {
                edges[i][0] = sc.nextInt();
                edges[i][1] = sc.nextInt();
            }

            Solution obj = new Solution();
            boolean ans = obj.isCyclic(V, edges);
            System.out.println(ans ? "true" : "false");
        }
        sc.close();
    }
}
// } Driver Code Ends


class Solution {
    private boolean dfs(int isTargetedNode,int node,List<List<Integer>>adj,boolean []visited){
        visited[node]=true;
        for(int x:adj.get(node)){
            if(x==isTargetedNode) return true;
            if(!visited[x] && dfs(isTargetedNode,x,adj,visited)) return true;
        }
        return false;
    }
    public boolean isCyclic(int V, int[][] edges) {
        List<List<Integer>>adj = new ArrayList<>();
        for(int i=0;i<V;i++){
            adj.add(new ArrayList<>());
        }
        for(int i=0;i<edges.length;i++){
            adj.get(edges[i][0]).add(edges[i][1]);
        }
        for(int i=0;i<V;i++){
            boolean []visited = new boolean[V];
            if(!visited[i] && dfs(i,i,adj,visited)) return true;
        }
        return false;
    }
}

