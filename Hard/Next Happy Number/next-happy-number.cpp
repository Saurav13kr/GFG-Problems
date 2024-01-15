//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public:
   int Sum(int N){
       int sum=0;
     while(N>0){
         int i=N%10;
         sum=sum+i*i;
         N=N/10;
     } 
     return sum;
   }
  bool ishappy(int N){
    while(1){
        if(N==1){
            return true;
        }
        if(N==89){
            return false;
        }
        N=Sum(N);
    }
}
    int nextHappy(int N){
        // code here
        int i=N+1;
        
        while(1){
            if(ishappy(i))
            return i;
            else
            i++;
        }
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends