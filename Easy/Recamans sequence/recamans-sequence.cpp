//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        vector<int>ans;
        unordered_map<int,int>mp;
        if(n==0){
            ans.push_back(0);
        }
        int a=0;
        ans.push_back(0);
        mp[a]++;
        for(int i=1;i<n;i++){
            int b=a-i;
            mp[b]++;
            if(mp[b]>1||b<0){
                b=a+i;
            }
            ans.push_back(b);
            mp[b]++;
            a=b;
        }
        return ans;
     // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends