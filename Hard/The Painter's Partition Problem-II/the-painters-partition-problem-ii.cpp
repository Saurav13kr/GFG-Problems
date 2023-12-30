//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    
    const long long MOD = 1000000007;
    
    bool isFeasible(int arr[],int n,int k,int ans){
        long long req=1,sum=0;
        for(int i=0;i<n;i++){
            if(sum + arr[i] > ans){
                req++;
                sum = arr[i];
            }else{
                sum += arr[i];
            }
        }
        return (req<=k);
    }
  
    long long minTime(int arr[], int n, int k)
    {
        long long sum=0;
        int maxVal = INT_MIN;
        for(int i=0;i<n;i++){
            sum += arr[i];
            maxVal = max(maxVal,arr[i]);
        }
        
        long long low=maxVal%MOD, high=sum%MOD;
        long long res=0;
        while(low<=high){
            long long mid = ((low%MOD+high%MOD)/2)%MOD;
            
            if(isFeasible(arr,n,k,mid)){
                res = mid%MOD;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends