//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
 class Solution {
  public:
    vector<int> twoRepeated (int arr[], int n) {
        vector<pair<int, int>>v;
        map<int, int>mp;
        for(int i=0;i<n+2;i++){
            mp[arr[i]]++;
            if( mp[arr[i]] > 1){
                v.push_back(make_pair(arr[i], i));
            }
            
        }
        
        vector<int>vec;
        if( v[1].second < v[0].second){
            vec.push_back(v[1].first);
            vec.push_back(v[0].first);
        }else{
            vec.push_back(v[0].first);
            vec.push_back(v[1].first);
        }
        
        return vec;
        
    }
};




//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}

// } Driver Code Ends