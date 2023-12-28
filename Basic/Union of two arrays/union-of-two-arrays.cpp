//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        sort(a,a+n);
        sort(b,b+m);
        int count = 0;      // count of common elements
        int duplicate = 0;  // count of duplicates
        int i,j;
        i = j = 0;
        
        //count duplicates
        while (i<n)
        {
            if (i != n-1 && (a[i] == a[i+1]))
            {
                i++;
                duplicate++;
                continue;
            }
            i++;
        }
        while (j<m)
        {
            if (j !=m-1 && (b[j] == b[j+1]))
            {
                j++;
                duplicate++;
                continue;
            }
            j++;
        }
        i = j = 0;
        while (i<n && j<m)
        {
            //code to ignore duplicates
            if (i != n-1 && (a[i] == a[i+1]))
            {
                i++;
                continue;
            }
            if (j !=m-1 && (b[j] == b[j+1]))
            {
                j++;
                continue;
            }
            
            //count the common elements between 2 arrays
            if (a[i]<b[j])
            {
                i++;
            }
            else if (a[i]>b[j])
            {
                j++;
            }
            else
            {
                i++;
                j++;
                count++;
                
            }
        }
        
        //complete counting 
        
        return m+n-count-duplicate;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends