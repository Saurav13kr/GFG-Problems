//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#include <vector>
using namespace std;

class Solution {
public:
    int maxSweetness(vector<int>& sweetness, int N, int K) {
        long long left = 1; // minimum sweetness
        long long right = 1e18; // maximum sweetness

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (isPossible(sweetness, N, K, mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left - 1; 
    }

private:
    bool isPossible(vector<int>& sweetness, int N, int K, long long target) {
        int pieces = 0;
        long long currentSweetness = 0;

        for (int i = 0; i < N; ++i) {
            currentSweetness += sweetness[i];

            if (currentSweetness >= target) {
                currentSweetness = 0;
                pieces++;

                if (pieces > K) {
                    return true;
                }
            }
        }

        return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends