//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int mini = INT_MAX;
    stack<int> s;
    public:
       int getMin(){
            if(s.empty())
                return -1;
            return mini;
       }
     
       int pop(){
            if(s.empty()){
                return -1;
            }
            
            int curr = s.top();
            s.pop();
            if(curr > mini) {
                return curr;
            } 
            
            else {
                int prevMin = mini;
                int val = 2*mini - curr;
                mini = val;
                return prevMin;
            }
       }

       void push(int data){
            if(s.empty()) {
                s.push(data);
                mini = data;
                
            } 
            
            else {
             	if(data < mini) {
                    s.push(2*data - mini);
                    mini = data;
                }
                else {
                    s.push(data);
                }
            }
       }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends