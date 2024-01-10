//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
 vector<int> maximumToys(int N, vector<int>& A, int Q, vector<vector<int>>& Queries) {
        // Initializing Data Structures
        vector<int> ans; // to store answers of queries
        vector<pair<int, int>> arr(N); // to store pair<value, original_idx>
        unordered_map<int, int> mp;// to store original_idx -> new_idx
        vector<int> ps(N, 0);// to store partial sum of sorted array
        
        // storing pair<value, original_idx> in arr
        for (int i = 0; i < N; i++) arr[i] = {A[i], i};
        // sorting arr
        sort(arr.begin(), arr.end());
        // storing original_idx -> new_idx (idx after sorting) in map
        for (int i = 0; i < N; i++) mp[arr[i].second] = i;
        // prepairing partial sum array
        ps[0] = arr[0].first;
        for (int i = 1; i < N; i++) ps[i] = ps[i - 1] + arr[i].first;
    
        // Processing Queries
        for (auto& x : Queries) {
            int cost = x[0];
            // finding pos such that cost <= ps[pos]
            int pos = lower_bound(ps.begin(), ps.end(), cost) - ps.begin();
            // if pos == N then all toys can be bought except the defected ones
            if (pos == N) {
                ans.push_back(N - (x.size() - 2));
                continue;
            }
            // if ps[pos] > cost then definately ps[pos-1] < cost so pos--
            if (ps[pos] > cost) pos--;
            // reducing cost by removing cost of taken toys
            cost -= ps[pos];
            // if nothing defective then we took pos+1 toys
            if (x[1] == 0) ans.push_back(pos + 1);
            else {
                int cnt = pos + 1;
                unordered_set<int> st; // to store the idx of toys which are defective and have not been taken
                for (int i = 2; i < x.size(); i++) {
                    // if the defective toy was taken then reduce the cnt and inc cost
                    if (mp[x[i] - 1] <= pos) cost += arr[mp[x[i] - 1]].first, cnt--;
                    else st.insert(x[i] - 1);
                }
                // check if any other toys could be taken with the left over cost
                for (int j = pos + 1; j < N && arr[j].first <= cost; j++)
                    if (!st.count(arr[j].second))
                        cost -= arr[j].first, cnt++;
                ans.push_back(cnt);
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    int N;
    cin>>N;
    vector<int>A(N);
    for(auto &i:A){
      cin>>i;
    }
    int Q;
    cin>>Q;
    vector<vector<int>> Queries(Q);
    for(int i=0;i<Q;i++){
      int x,y;
      cin>>x>>y;
      Queries[i].push_back(x);
      Queries[i].push_back(y);
      for(int j=0;j<Queries[i][1];j++){
        cin>>x;
        Queries[i].push_back(x);
      }
    }
    Solution obj;
    auto ans =obj.maximumToys(N,A,Q,Queries);
    for(auto i:ans)
      cout<<i<<" ";
    cout<<endl;
 }
}
// } Driver Code Ends