//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        map<int,int>freq;
        for(int i=0;i<N;i++){
            
                freq[arr[i]]++;
            
        }
        int ans=-1;
        map<int,int>::iterator it;
        for(it=freq.begin(); it!= freq.end();it++){
            if(it->second==1){
                ans=it->first;
            }
        }
        
        return ans;
        
    
        
        
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends