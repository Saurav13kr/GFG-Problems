//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        int col=INT_MAX; string ans="";
        for(auto &b: arr){col=min(col, (int)b.size());}
        for(int i=0; i<col; i++){
            bool fg=true;
            for(int j=1; j<arr.size(); j++)
            {
                if(arr[j-1][i]!=arr[j][i]){fg=false;}
            }
            if(fg==false){break;}
            ans+=arr[0][i];
        }
        return ans==""?"-1":ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends