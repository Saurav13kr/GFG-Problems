class Solution {
    void get_unique_k_number(int n, int k, vector<vector<int>> &ans, vector<int> &temp, vector<int> &ninenumber, int index){
        if(temp.size()>k){
            return;
        }
        if(temp.size()==k){
            int sum= accumulate(temp.begin(), temp.end(),  0);
            if(sum==n){
                ans.push_back(temp);
            } 
            return;
        }
        for(int i=index; i<ninenumber.size(); i++)
        {
            temp.push_back(ninenumber[i]);
            get_unique_k_number(n, k, ans, temp,ninenumber, i+1);
            temp.pop_back();
        }
    }
  public:
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        int  index=0;
        vector<int> ninenumber= {1,2,3,4,5,6,7,8,9};
        get_unique_k_number(n, k, ans, temp, ninenumber, index);
        return ans;
    }
};