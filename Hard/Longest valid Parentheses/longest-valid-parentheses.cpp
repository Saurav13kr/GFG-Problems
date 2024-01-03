//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string s){
        // code here
        stack<pair<char,int>>z;
        vector<pair<int,int>>v;
        for(int i=0; i<s.size(); i++){
            if(s[i]==')'){
                if(z.size() and z.top().first=='('){
                    v.push_back({z.top().second, i});
                    z.pop();
                }
            }
            else{
                z.push({'(', i});
            }
        }
       // sort(v.begin(), v.end());
       if(v.size()==0){
           return 0;
       }
       int ans=0, c=0;
       int st=v[v.size()-1].first;
        int e=v[v.size()-1].second;
           ans=max(ans, e-st+1);
       for(int i=v.size()-2; i>=0; i--){
        //   st=v[i].first;
           if(v[i].second+1==st){
               st=v[i].first;
                
           }
           else if(v[i].first<st){
               st=v[i].first;
               e=v[i].second;
           }
           
           ans=max(ans, e-st+1);
           
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends