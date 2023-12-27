//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool isAlpha(string str){
        int c=0;
        for(int i=0;i<str.length();i++){
            if(isalpha(str[i])) return true;
            if(str[i]=='-'||str[i]=='+') c++;
            if(isdigit(str[i])&&(isalpha(str[i+1])||str[i+1]=='-'||str[i+1]=='+')) return true;
        }
            if(c>1) return true;
            return false;
    }
    int atoi(string str) {
        //Your code here
        if(isAlpha(str)){
            return -1;
        }
        int n=stoi(str);
        return n;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends