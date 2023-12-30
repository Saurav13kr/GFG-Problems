//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        sort(arr,arr+n);

        vector <int> v1;
        // int v1len = v1.size();
        for ( int i=0;i<n-1;i++){
            if ( arr[i]==arr[i+1]){
                if (v1.empty()){
                    v1.push_back(arr[i]);
                }
                else if(!v1.empty() && v1.back()!=arr[i]){
                    v1.push_back(arr[i]);
                }
            }
        }
        // if duplicates are not found then return -1
        if(v1.empty()){
            v1.push_back(-1);
            return v1;
        }
        // else sort the array and return it.
        sort(v1.begin(),v1.end());
        return v1;// code here
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends