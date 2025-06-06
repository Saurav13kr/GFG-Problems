class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here.
        int p=31;
        int mod=1e9+9;
        int n=pat.size();
        int m=txt.size();
        
        vector<long long>p_pow(m);
        p_pow[0]=1;
        for(int i=1;i<m;i++){
            p_pow[i]=(p_pow[i-1]*p)%mod;
        }
        
        vector<long long>h_txt(m+1,0);
        for(int i=0;i<m;i++){
            h_txt[i+1]=(h_txt[i]+(txt[i]-'a'+1)*p_pow[i])%mod;
        }
        long long h_pat=0;
        for(int i=0;i<n;i++){
            h_pat=(h_pat+(pat[i]-'a'+1)*p_pow[i])%mod;
        }

        vector<int>ans;
        for(int i=0;i+n<=m;i++){
            long long poly=(h_txt[i+n]+mod-h_txt[i])%mod;
            if(poly==(h_pat*p_pow[i])%mod){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};