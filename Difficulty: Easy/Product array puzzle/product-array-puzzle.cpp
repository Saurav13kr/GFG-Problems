//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution {
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        vector<long long int>ans;
        long long int zeroCount=0;
        long long int mult=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            mult*=nums[i];
            else
            zeroCount++;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(zeroCount==1)
                ans.push_back(mult);
                else
                    ans.push_back(0);
            }
            else{
                if(zeroCount)
                ans.push_back(0);
                else
                ans.push_back(mult/nums[i]);
            }
            
        }
        return ans;
    }
};




//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends