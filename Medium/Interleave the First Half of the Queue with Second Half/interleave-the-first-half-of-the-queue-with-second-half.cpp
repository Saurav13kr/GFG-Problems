//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
void reverse(vector<int>& arr){
    int s=0; int e = arr.size()-1;
    while(s<e){
        swap(arr[s++], arr[e--]);
    }
}
    vector<int> rearrangeQueue(queue<int> &q){
        stack<int> st;     
        vector<int>ans;
        int n = q.size()/2;
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            st.push(ele);
        }
        while(n!=0){
            int top = st.top();
            st.pop();
            q.push(top);
            n--;
        }
        while(!st.empty()){
            int ele = q.front();
            q.pop();
            ans.push_back(ele);
            ele = st.top();
            st.pop();
            ans.push_back(ele);
        }
        reverse(ans);
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends