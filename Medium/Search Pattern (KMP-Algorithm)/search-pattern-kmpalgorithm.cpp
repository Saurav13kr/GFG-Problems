//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int i,j;
            int n=txt.size(),m=pat.size();
            vector<int>ans;
            int lps[m];
           lps[0]=0;
           j=0,i=1;
        while(i<m)
        {
            if(pat[i]==pat[j])
            {
                lps[i]=j+1;
                j++;
                i++;
            }
            else
            {
                if(j !=0)
                {
                    j=lps[j-1];
                }
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        j=0,i=0;
            while((n-i)>=(m-j))
            {
                if(pat[j]==txt[i])
                {
                    i++;
                    j++;
                }
                if(j==m)
                {
                    ans.push_back(i-j+1);
                    j=lps[j-1];
                }
                else if(i<n && pat[j]!=txt[i])
                {
                    if(j !=0)
                    {
                        j=lps[j-1];
                    }
                    else
                    {
                        i++;
                    }
                }
            }
            if(ans.size()==0)
            {
                ans.push_back(-1);
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends