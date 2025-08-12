class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        int n=prices.size();
        int lim=(n+k)/(1+k);
        int maxi=0;
        int mini=0;
        sort(prices.begin(),prices.end());
        
        for(int i=0;i<lim;i++)
        {
            mini+=prices[i];
            maxi+=prices[n-1-i];
        }
        return {mini,maxi};
    }
};

