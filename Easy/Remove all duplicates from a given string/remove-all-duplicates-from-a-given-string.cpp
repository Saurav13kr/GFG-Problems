//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    string removeDuplicates(string str) {
        // code here
        long x=str.length();
        string s;
        for(int i;i<str.length();i++)
        {
            char c=str[i];
            size_t a=s.find(c);
            if(a>x)
            {
               s+=c;
            }
            
        }
        return s;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends