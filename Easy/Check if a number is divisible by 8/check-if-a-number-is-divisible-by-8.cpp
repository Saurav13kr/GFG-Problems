//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        int n = s.size();
        
        if(n>=3){
            int num = (s[n-1]-'0')*1 + (s[n-2]-'0')*10 + (s[n-3]-'0')*100;
            
            if(num%8==0) return 1;
            return -1;
        }
        
        else{
            
            int num = stoi(s);
            
            if(num%8==0) return 1;
            return -1;
        }
    }
};





//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends