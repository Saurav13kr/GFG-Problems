//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
       public:
        
    int maxIndexDiff(int a[], int n) 
    { 
        map<int,int> mp;
        int res=0;
        for(int i=n-1;i>=0;i--){
            auto it=mp.lower_bound(a[i]);
            if(it!=mp.end()){
                res=max(res,it->second-i);
                mp[a[i]]=it->second;
            }else{
                mp[a[i]]=i;
            }
        }
        return res;
    }
};




//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends