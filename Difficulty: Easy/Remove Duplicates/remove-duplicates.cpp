//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
     vector<int>vec(26,-1);
     string result = "";
     for(int i =0;i<str.size();i++)
     {
         if(vec[str[i]-'a']==-1){
             vec[str[i]-'a']=1;
             result+=str[i];
         }
         else 
         continue;
     }
     return result;
    
    }
};




//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends