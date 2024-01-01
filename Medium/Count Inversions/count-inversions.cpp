//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    long long  c = 0;
    void merge(long long arr[],long long  low,long long mid,long long high){
        vector<long long> temp;
         long long left = low;
         long long right = mid+1;
         while(left<=mid and right<=high){
             if(arr[left]<=arr[right]){
                 temp.push_back(arr[left]);
                 left++;
             }
             else{
                 temp.push_back(arr[right]);
                 c = c+(mid-left+1);
                 right++;
             }
         }
         while(left<=mid){
             temp.push_back(arr[left]);
             left++;
         }
         while(right<=high){
              temp.push_back(arr[right]);
              right++;
         }
         for(long long i = low;i<=high;i++){
             arr[i] = temp[i-low];
         }
    }
    void mergesort(long long arr[],long long low,long long high){
        if(low == high) return;
        long long  mid = (low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        mergesort(arr,0,N-1);
        return c;
    }

};



//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends