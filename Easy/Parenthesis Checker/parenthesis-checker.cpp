//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        int i=0, n=x.length();
        stack<char> s;
        while(i<n){
            char ch = x[i];
            if(ch=='{' || ch=='(' || ch=='[') s.push(ch);
            else{
                if(s.empty()) return false;
                else{
                    char top = s.top();
                    if(ch==']' && top == '['){
                        s.pop();
                    }else if(ch==')' && top == '('){
                        s.pop();
                    }else if(ch=='}' && top=='{'){
                        s.pop();
                    }else return 0;
                }
            }
            i++;
        }
        if(s.empty()) return 1;
        return 0;
    }

};



//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends