//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


#include<bits/stdc++.h>
class Solution {
public:

    set<string> ans; 

    void solve(const string& S, string cur, vector<int>& vis) {
        if (cur.length() == S.length()) {
            ans.insert(cur);  
            return;
        }

        for (int i = 0; i < S.length(); i++) {
            if (!vis[i]) {
                vis[i] = 1;
                solve(S, cur + S[i], vis);
                vis[i] = 0;
            }
        }
    }

    vector<string> find_permutation(const string& S) {
        vector<int> vis(S.length(), 0);
        string str;
        solve(S, str, vis);
        return vector<string>(ans.begin(), ans.end());
    }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends