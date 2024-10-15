//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int subArraySum(vector<int>& arr, int tar) {
        unordered_map<int,int>mp;
        int res=0;
        int ans=0;
        
        for(int i=0;i<arr.size();i++)
        {
            res+=arr[i];
            if(res==tar)
            ans++;
            else if(mp.find(res-tar)!=mp.end())
            ans+=mp[res-tar];
            mp[res]++;
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends