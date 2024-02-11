//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minChar(string str){
        string rev=str;
        reverse(rev.begin(),rev.end());
        string s=str+'&';
        s+=rev;
        vector<int>lps(s.size(),0);
        int pre=0,suf=1;
        while(suf<s.size())
        
        {
            if(s[pre]==s[suf])
            {
                lps[suf]=pre+1;
                pre++;
                suf++;
            }
            else
            {
                if(pre==0)
                {
                    suf++;
                }
                else
                {
                    pre=lps[pre-1];
                }
            }
        }
        return(str.size()-lps[s.size()-1]);//Write your code here
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends