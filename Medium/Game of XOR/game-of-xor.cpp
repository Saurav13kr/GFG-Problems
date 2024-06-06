//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int gameOfXor(int N , int A[]) {
        // code here
        int ans = 0;
        for(int i = 0; i < N; i++){
            int left = i + 1, right = N - i;
            if(left % 2 == 0 || right % 2 == 0){
                continue;
            }
            ans ^= A[i];
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int N;
        
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.gameOfXor(N,A) << endl;
    }
    return 0;
}
