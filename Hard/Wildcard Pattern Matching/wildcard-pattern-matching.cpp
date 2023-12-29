//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
/*You are required to complete this method*/
    int wildCard(string s1,string s2){
        int n = s1.length();
        int m = s2.length();
        int t[n+1][m+1];
        t[0][0] =1;
        for(int i =1; i<m+1; i++) t[0][i] =0;
        for(int i =1; i<n+1; i++){
            if(s1[i-1] == '*') t[i][0] = t[i-1][0];
            else t[i][0] = 0;
        }
        
        for(int i =1; i<n+1; i++){
            for(int j =1; j<m+1; j++){
                if(s1[i-1] == '?') t[i][j] = t[i-1][j-1];
                else if(s1[i-1] == '*') t[i][j] = t[i-1][j] || t[i][j-1];
                else if(s1[i-1] == s2[j-1]) t[i][j] = t[i-1][j-1];
                else t[i][j] = 0;
            }
        }
        return t[n][m];
        
    }
};



//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends