//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countBits(int N, long long int A[])
    {
        // code here
        long long mod = 1e9 + 7;
        int cnt[64] = {0};
        
        for (int i = 0; i < 64; i++) {
            long long int x = (1 << i);
            
            for (int j = 0; j < N; j++) {
                // cout << (x & A[j]) << '\n';
                if (x & A[j])
                    cnt[i] += 1;
            }
        }

        
        int ans = 0;
        for (int i = 0; i < 64; i++) {
            // cout << i << " -> " << cnt[i] << '\n';
            ans = (ans + ((N - cnt[i])%mod * cnt[i]%mod)) % mod;
            // ans = ans % mod;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends