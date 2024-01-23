//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s) {
        unordered_set<string> wordSet(dict.begin(), dict.end());
        vector<string> result;
        string current;

        wordBreakHelper(s, 0, wordSet, current, result);

        return result;
    }

private:
    void wordBreakHelper(const string& s, int start, const unordered_set<string>& wordSet, string& current, vector<string>& result) {
        if (start == s.length()) {
            // We reached the end of the string, add the current word break to the result
            result.push_back(current);
            return;
        }

        for (int end = start + 1; end <= s.length(); ++end) {
            string word = s.substr(start, end - start);

            if (wordSet.find(word) != wordSet.end()) {
                // Word is in the dictionary, explore further
                string previous = current.empty() ? word : (current + " " + word);
                wordBreakHelper(s, end, wordSet, previous, result);
            }
        }
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends