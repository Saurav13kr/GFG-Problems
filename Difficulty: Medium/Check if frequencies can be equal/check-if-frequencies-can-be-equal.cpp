class Solution {
  public:
    bool sameFreq(string& s) {
        vector<int> v(26,0);
        for(auto it:s) v[it-'a']++;
        vector<int> freq;
        for(auto it:v){
            if(it>0) freq.push_back(it);
        }
        int n=freq.size();
        sort(freq.begin(),freq.end());
        if(freq.front()==freq.back()) return true;
        if(freq[0]==1 && freq[1]==freq.back()) return true;
        if(freq[n-1]==freq[n-2]+1 && freq[0]==freq[n-2]) return true;
        return false;
    }
};