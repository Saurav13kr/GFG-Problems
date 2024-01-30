//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    void helper(string& ans,string s,unordered_set<string>& set,int n,int k,int p){
        string temp=s.substr(s.size()-n+1);
   
        for(int i=0;i<k && ans.size()!=p;i++){
            char ch=(char)((int)'0'+i);
            string temp2=temp+ch;
            if(set.find(temp2)==set.end()){
                set.insert(temp2);
                helper(ans,s+ch,set,n,k,p);
                set.erase(temp2);
            }
        }
        if(s.size()==p) ans=s;
    }
public:
    string findString(int n, int k) {
        string s="";
        string ans="";
        for(int i=0;i<n;i++) s+='0';
        unordered_set<string> set;
        set.insert(s);
        int p=pow(k,n)+n-1;
        helper(ans,s,set,n,k,p);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
} 
// } Driver Code Ends