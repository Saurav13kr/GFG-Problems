//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int i=0;
        int j=0;
        int n=arr1.size();
        int m=arr2.size();
        
        while(i<n && j<m){
            if (k==1) return arr1[i]<arr2[j]?arr1[i]:arr2[j];
            if(arr1[i]<arr2[j]) i++;
            else j++;
            k--;
        }
        while(i<n) {
            if (k==1) return arr1[i];
            i++;
            k--;
        }
        while(j<m){
            if (k==1) return arr2[j];
            j++;
            k--;
        }
       return -1;
    }
};



//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends