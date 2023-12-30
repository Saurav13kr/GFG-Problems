//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution{
  public:
    struct Compare{
        bool operator() (const pair<int, string>& a, const pair<int, string>& b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first<b.first;
        }
    };

    vector<string> winner(string arr[],int n)
    {

        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        priority_queue<pair<int,string>, vector<pair<int,string>>, Compare> pq;
        
        for(auto& p : mp){
            pq.push({p.second,p.first});
        }
        
        return {pq.top().second,to_string(pq.top().first)};
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends