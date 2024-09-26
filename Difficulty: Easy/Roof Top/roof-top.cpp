//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxStep(vector<int>& arr) {
        int cnt = 0;
        int mx_cnt = 0;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i] > arr[i-1])
            {
                cnt++;
                mx_cnt = max(cnt, mx_cnt);
            } 
            else {
                cnt=0;
            }
        }
        return mx_cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.maxStep(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends