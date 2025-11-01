class Solution {
    public int idx=0;
    public void dfs(List<List<Integer>> graph,boolean[] visited,int[] stack,int node){
        visited[node] = true;
        
        for(int neighbour:graph.get(node)){
            if(visited[neighbour]) continue;
            visited[neighbour] = true;
            dfs(graph,visited,stack,neighbour);
        }
        
        stack[idx++] = node;
    }
    public ArrayList<Integer> findOrder(int n, int[][] prerequisites) {
        // code here
        ArrayList<Integer> list = new ArrayList<>();
        List<List<Integer>> graph = new ArrayList<>();
        for(int i=0;i<n;i++) graph.add(new ArrayList<>());
        for(int[] edge:prerequisites){
            int src = edge[1];
            int dest = edge[0];
            graph.get(src).add(dest);
        }
        boolean[] visited = new boolean[n];
        int[] stack = new int[n];
        for(int i=0;i<n;i++){
            if(!visited[i])
            {
                dfs(graph,visited,stack,i);
            }
        }
        
        for(int i=n-1;i>=0;i--){
            list.add(stack[i]);
        }
        
        return list;
    }
}