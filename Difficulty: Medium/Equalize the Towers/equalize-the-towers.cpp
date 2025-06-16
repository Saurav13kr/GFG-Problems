class Solution {
    
    int getCost(vector<int>&heights, vector<int>&cost, int k){
        int amount = 0;
        int n = heights.size();
        
        for(int i=0; i<n; i++){
            amount += abs(heights[i]-k)*cost[i];
        }
        
        return amount;
    }
    
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int lo=INT_MAX, hi=INT_MIN;
        int n = heights.size();
        for(int i=0; i<n; i++){
            lo=min(lo, heights[i]);
            hi=max(hi, heights[i]);
        }
        
        while(lo<hi){
            int mid = (hi+lo)/2;
            if(getCost(heights, cost, mid)>=getCost(heights, cost, mid+1)){
                lo=mid+1;
            }
            else if(getCost(heights, cost, mid)<getCost(heights, cost, mid+1)){
                hi=mid;
            }
            
        }
        return getCost(heights, cost, lo);
        
    }
};