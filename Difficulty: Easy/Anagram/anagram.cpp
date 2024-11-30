//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
   
    bool areAnagrams(string& s1, string& s2) {
        
        if(s1.size()!=s2.size()) return false;
        
        map<int,int>mp;
        for(auto elem : s1) {
            mp[elem]++;
        }
        
        for(auto elem : s2)
        {
            mp[elem]--;
            if(mp[elem]==0)
            {
                mp.erase(elem);
            }
        }
        
        return mp.empty() ? true : false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends