class Solution {
    public static int minCost(int[] arr) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int ans = 0;

        for(int next : arr) 
        {
            pq.offer(next);
        }
        
        while(pq.size() > 1) {
            int first = pq.poll();
            int second = pq.poll();
            ans += first + second;
            pq.offer(first + second);
        }
        return ans;
    }
}