//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.


class Solution {
  public:
  int Solve(int idx,vector<int>&arr1,vector<int>&arr2){
      
      int i=0;
      int j=0;
      int ele=0;
      bool istrue=false;
      while(i<arr1.size() && j<arr2.size()){
          if(arr1[i]<arr2[j]){
              ele=arr1[i];
               i++;
          } else{
              ele=arr2[j];
              j++;
          }
          if(i+j==idx){
              istrue=true;
          break;
          }
          
      }
      while(!istrue && i<arr1.size()){
          ele=arr1[i];
          i++;
          if(i+j==idx){
              istrue=true;
          break;
          }
      }
      while(!istrue && j<arr2.size()){
          ele=arr2[j];
          j++;
          if(i+j==idx)
          break;
      }
      return ele;
  }
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int n1=arr1.size();
        int n2=arr2.size();
        int sum=0;
        if((n1+n2)%2==0){
            int idx1=(n1+n2)/2;
            int idx2=(n1+n2-1)/2;
            int num1=Solve(idx1+1,arr1,arr2);
            int num2=Solve(idx2+1,arr1,arr2);
            sum=sum+num1+num2;
        }
        else{
            int idx=(n1+n2)/2;
            int num=Solve(idx+1,arr1,arr2);
            sum=num;
        }
        return sum;
    }
};






//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends