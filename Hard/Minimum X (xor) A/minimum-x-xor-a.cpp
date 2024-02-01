//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int count=0;
       for(int i=31;i>=0;i--){
           if(b&(1<<i)) count++;
       }
       vector<int>v(32,0);
       int count1=0;
       for(int i=31;i>=0;i--){
           if(a&(1<<i)) v[i]=1;
           count1+=v[i];
       }
       if(count>count1){
           vector<int>b(32,0);
           int k=count-count1;
           for(int i=0;i<32;i++){
               if(v[i]==0 && k>0){
                   b[i]=1;
                   v[i]=1;
                   k--;
               }
           }
           for(int i=31;i>=0;i--){
               if(b[i]==0 && v[i]==1 && count>0){
                   v[i]=0;
               }
           }
           int sum=0;
           for(int i=31;i>=0;i--){
               if(v[i]) sum+=(1<<i);
           }
           return a^sum;
       }
       else{
           for(int i=31;i>=0;i--){
               if(v[i]==1 && count>0){
                   v[i]=0;
                   count--;
               }
           }
           int sum=0;
           for(int i=31;i>=0;i--){
               if(v[i]) sum+=(1<<i);
           }
           return a^sum;
       }
      
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends