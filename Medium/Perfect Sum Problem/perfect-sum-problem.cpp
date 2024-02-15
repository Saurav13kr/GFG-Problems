//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        int t[n+1][sum+1];
        int MOD = 1e9 + 7;
        for(int j=0;j<sum+1;j++){
            t[0][j]=0;
        }
        t[0][0]=1;
       
         for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                //we have done j from 0 to sum+1 to consider 0s in our array
                if(arr[i-1]<=j){
                    t[i][j]= (t[i-1][j-arr[i-1]] + t[i-1][j]) % MOD ;
                }
                else
                t[i][j]=t[i-1][j];
            }
        } 
        return t[n][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends