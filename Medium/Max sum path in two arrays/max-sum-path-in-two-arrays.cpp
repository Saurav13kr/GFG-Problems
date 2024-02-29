//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method*/
    int max_path_sum(int A[], int B[], int m, int n)
{
    // Initialize variables
    int i=0,j=0,suma=0,sumb=0,res=0;

    // Traverse both arrays
    while(i<m && j<n){
        // If elements are same in both arrays
        if(A[i]==B[j]){
            // Add maximum of two sums of common subarrays
            res += max(suma, sumb) + A[i];

            // Move to next element in both arrays
            i++;
            j++;

            // Reset sums
            suma = 0;
            sumb = 0;
        }
        // If element in array B is smaller, move to next element in B
        else if(A[i]>B[j]){
            sumb += B[j];
            j++;
        }
        // If element in array A is smaller, move to next element in A
        else{
            suma += A[i];
            i++;
        }
    }

    // Add remaining elements in array B to sumb
    if(i==m && j<n){
        for(int k=j; k<n; k++){
            sumb += B[k];
        }
        // Add maximum of two sums of common subarrays
        res += max(suma, sumb);
    }
    // Add remaining elements in array A to suma
    else if(j==n && i<m){
        for(int k=i; k<m; k++){
            suma += A[k];
        }
        // Add maximum of two sums of common subarrays
        res += max(suma, sumb);
    }

    // Return maximum path sum
    return res;
}
};



//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}


// } Driver Code Ends