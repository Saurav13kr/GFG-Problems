//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        unordered_map<int,int>mp;
        int sum=0,n=nums.size(),cnt=0;
        if(n%2) return false;
        for(int i=0;i<n;i++) nums[i]%=k;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int d=k-nums[i];
            if(nums[i]==0) d=0;
            if(mp.find(d)!=mp.end()){
                mp[d]--;
                if(mp[d]==0) mp.erase(d);
                cnt++;
            }
            else mp[nums[i]]++;
        }
        return cnt==n/2;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends