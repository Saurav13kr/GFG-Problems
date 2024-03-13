//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void sort_rows(vector<vector<int>> &hist, int r, int c){
        for(int i=0; i<r; i++){
            vector<int> freq(r+1, 0);
            for(int j=0; j<c; j++) freq[hist[i][j]]++;
            
            int k = 0;
            for(int num=r; num>=0; num--){
                if(freq[num] == 0) continue;
                int x = freq[num];
                
                while(x--) {
                    hist[i][k++] = num;
                }
            }
        }
    }

	// Returns area of the largest rectangle of 1's
	int maxArea(vector<bool> mat[], int r, int c) {
	    vector<vector<int>> hist(r, vector<int> (c, 0));
	    
	    for(int j=0; j<c; j++){
	        hist[0][j] = mat[0][j];
	    }
	    
	    for(int i=1; i<r; i++){
	        for(int j=0; j<c; j++){
	            if(mat[i][j] == 1) hist[i][j] = hist[i-1][j] + 1;
	            else hist[i][j] = 0;
	        }
	    }
	    
	    sort_rows(hist, r, c);

        int ans = 0;

        for(int i=0; i<r; i++){
            for(int j=1; j<c+1; j++){
                ans = max(ans, j*hist[i][j-1]);
            }
        }
        
        return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c, x;
        cin >> r >> c;
        vector<bool> mat[r];
        for (int i = 0; i < r; i++) {
            mat[i].assign(c, false);
            for (int j = 0; j < c; j++) {
                cin >> x;
                mat[i][j] = x;
            }
        }
        Solution ob;
        auto ans = ob.maxArea(mat, r, c);
        cout << ans << "\n";

    }
    return 0;
}

// } Driver Code Ends