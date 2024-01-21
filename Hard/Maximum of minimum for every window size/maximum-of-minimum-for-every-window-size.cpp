//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:

    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        vector<int> rightNS(n, 0);
        vector<int> leftNS(n, 0);
        stack<int> st;
        
        for(int i=0; i<n; i++)
        {
            while(!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
                
            if(st.empty())
                leftNS[i] = -1;
            else
                leftNS[i] = st.top();
                
            st.push(i);
        }
        
        while(!st.empty())
            st.pop();
        
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
                
            if(st.empty())
                rightNS[i] = n;
            else
                rightNS[i] = st.top();
                
            st.push(i);
        }
        
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            int winSize = rightNS[i] - leftNS[i] - 2;

            ans[winSize] = max(ans[winSize], arr[i]);
        }

        for(int i=n-2; i>=0; i--)
        {
            ans[i] = max(ans[i], ans[i+1]);
        }
        
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends