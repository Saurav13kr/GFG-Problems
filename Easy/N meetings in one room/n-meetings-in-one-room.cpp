//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
   int maxMeetings(int start[], int end[], int n) {
        // Your code here
        vector<pair<int,int>>pa;
        for(int i=0;i<n;i++)
        {
            pa.push_back(make_pair(end[i], i));
        }
        
        sort(pa.begin(), pa.end());
        int cnt=1;
        int last=pa[0].first;
        for(int i=1;i<n;i++)
        {
            if(start[pa[i].second]>last)
            {
                cnt++;
                last=pa[i].first;
            }
            
        }
        
        return cnt;
    
// Your code here
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
