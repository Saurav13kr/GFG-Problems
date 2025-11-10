class Solution{
    private:
    
    int solve(int ind,int buy,vector<int>&arr,vector<vector<int>>&dp){
        if(ind>=arr.size()){
            return 0;
        }
        
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        int profit=0;
        
        if(buy){
            profit=max(-arr[ind]+solve(ind+1,0,arr,dp),solve(ind+1,1,arr,dp));
        }
        else{
            profit=max(arr[ind]+solve(ind+2,1,arr,dp),solve(ind+1,0,arr,dp));
        }
        
        return dp[ind][buy]=profit;
    }
    
    public:
    int maxProfit(vector<int>&arr) {

        vector<int>next1(2,0);
        vector<int>next2(2,0);
        vector<int>curr(2,0);
        int n=arr.size();
       
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                
                if(buy){
                    profit=max(-arr[ind]+next1[0],next1[1]);
                }
                else{
                    profit=max(arr[ind]+next2[1],next1[0]);
                }
                
                curr[buy]=profit;
            }
            next2=next1;
            next1=curr;
        }
        
        return curr[1];
    }
};