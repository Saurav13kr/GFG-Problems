//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	 int Palindrome(string &str,int s,int e)
    {
        if(s>e)     // base case
        return 1; // saare cases check hogaye 
        
        if(str[s]!=str[e])
        {
            return 0;
        }
        else
        {
            s++;
            e--;
            Palindrome(str,s,e); // recursive relation
        }
    }
 
int isPalindrome(string S)
{
    return Palindrome(S,0,S.length()-1);
}
};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends