//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string ip) {
        // code here
        stringstream ss(ip);
        string segment;
        vector<int> segments;
        
        while (std::getline(ss, segment, '.')) {
            if (segment.empty() || (segment.size() > 1 && segment[0] == '0')) {
                // Check for empty segments and leading zeros
                return false;
            } try {
                int num = std::stoi(segment);
                if (num < 0 || num > 255) 
                {
                    return false;
                }
                segments.push_back(num);
            } catch (...) 
            {
                return false;  // Catch any conversion error
            }
        }
    
        if (segments.size() != 4) {
            return false;
        }
    
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends