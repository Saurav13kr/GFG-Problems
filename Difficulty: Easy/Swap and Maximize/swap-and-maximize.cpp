//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends

class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> nums; 
        sort(arr.begin(), arr.end());
        
        int i=0; int j = n-1;
        
        while(i <= j){
            if(i == j){
                nums.push_back(arr[i]);
            }else{
                nums.push_back(arr[i]);
                nums.push_back(arr[j]);
            }
            i++;
            j--;
        }
        
        long long sum = 0;
        
        for(int i=0 ;i<n-1; i++)
        {
            sum += abs(nums[i] - nums[i+1]);
        }
        
        sum += abs(nums[n-1] - nums[0]);
        
        return sum;
        
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends