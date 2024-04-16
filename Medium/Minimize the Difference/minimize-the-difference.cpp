//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        deque<int>dq;
        vector<int>maxvals,minvals;
        int i = k;  
        while(i < n){
            while(!dq.empty() && arr[dq.back()] < arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            i++;
        }
        int p = k;
        while((i % n) < n - k){
            maxvals.push_back(arr[dq.front() % n]);
            while(!dq.empty() && dq.front() <= p){
                dq.pop_front();
            }
            while(!dq.empty() && arr[(dq.back() % n)] < arr[i % n]){
                dq.pop_back();
            }
            dq.push_back(i);
            i++, p++;
        }
        maxvals.push_back(arr[dq.front() % n]);
        p = k;
        while(!dq.empty()){
            dq.pop_back();
        }
        i = k;
        while(i < n){
            while(!dq.empty() && arr[dq.back()] > arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            i++;
        }
        while((i % n) < n - k){
            minvals.push_back(arr[dq.front() % n]);
            while(!dq.empty() && dq.front() <= p){
                dq.pop_front();
            }
            while(!dq.empty() && arr[dq.back() % n] > arr[i % n]){
                dq.pop_back();
            }
            dq.push_back(i);
            i++, p++;
        }
        minvals.push_back(arr[dq.front() % n]);
        int ans = INT_MAX;
        for(i = 0; i <= n - k; i++){
            ans = min(ans, maxvals[i] - minvals[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends