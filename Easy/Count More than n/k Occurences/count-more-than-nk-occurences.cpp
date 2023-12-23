//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int countOccurence(int arr[], int n, int k) {
        unordered_map<int,int> ans;
        for(int i=0;i<n;i++)
        ans[arr[i]]++;
        int count = 0;
       for (auto i = ans.begin(); i != ans.end(); i++) {
         if (i->second > (n / k)) {
        count++;
         }
        }
        return count;

    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends