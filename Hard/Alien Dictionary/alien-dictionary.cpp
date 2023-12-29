//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
    unordered_map<char,vector<char>>mp;
    for(int i=0;i<N-1;i++){
    string s1=dict[i];
    string s2=dict[i+1];
    int x=0,y=0;
    while(x<s1.length() && y<s2.length()){
        if(s1[x]!=s2[y]){
            mp[s1[x]].push_back(s2[y]);
            break;
        }
        x++;y++;
    }
    }
    vector<int>indegree(K,0);
    for(auto it:mp){
        for(auto val:it.second)indegree[val-'a']++;
    }
    //toposort
    queue<char>q;
    for(char i='a';i<(char)(K+'a');i++)if(indegree[i-'a']==0)q.push(i);
    string res;
    while(!q.empty()){
        char temp=q.front();
        q.pop();
        res.push_back(temp);
        for(auto it:mp[temp]){
            indegree[it-'a']--;
            if(indegree[it-'a']==0)q.push(it);
        }
    }
    return res;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends