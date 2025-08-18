class Solution {
  public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int i = 0;
        while(citations[i]>=i+1 && i<citations.size()) i++;
        return i;
    }
};