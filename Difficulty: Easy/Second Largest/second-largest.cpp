//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int firstLargest = -1;
        int secondLargest = -1;
        
        for(int &num : arr) 
        {
            if(num > firstLargest) 
            {
                secondLargest = firstLargest;
                firstLargest = num;
            } else if(num > secondLargest && num != firstLargest) {
                secondLargest = num;
            }
        }
        return secondLargest;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends