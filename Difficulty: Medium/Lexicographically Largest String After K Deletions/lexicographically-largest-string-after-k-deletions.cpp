class Solution {
  public:
    string maxSubseq(string& s, int k) {
        int n = s.size();
        int keep = n - k;  // number of characters to keep
        string ans;

        for (char ch : s) {
            while (!ans.empty() && k > 0 && ans.back() < ch) 
            {
                ans.pop_back();
                k--;
            }
            ans.push_back(ch);
        }

        // Only keep first (n - k) characters
        ans.resize(keep);
        return ans;
    }


};
