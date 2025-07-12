class Solution {
  public:
    int m, n;
    vector<pair<int, int>> dir = {{-1, 1}, {0, 1}, {1, 1}};
    int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if (i < 0 || i >= m || j < 0 || j >= n) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = INT_MIN;
        for (auto& it : dir){
            ans = max(ans, mat[i][j] + f(i+it.first, j+it.second, mat, dp));
        }
        return dp[i][j] = ans;
    }
    int maxGold(vector<vector<int>>& mat) {
        // code here
        m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int res = INT_MIN;
        for (int i = 0; i < m; i++){
            res = max(res, f(i, 0, mat, dp));
        }
        return res;
    }
};