class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> popularity(n, 0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++)
            {
                popularity[j] += mat[i][j];
            }
        }
        for(int i = 0; i<n; i++){
            int count = 0;
            for(int j = 0; j<n; j++)
            {
                if(mat[i][j] == 0) count++;
            }
            if(count == n-1 && popularity[i] == n) return i;
        }
        return -1;
    }
};