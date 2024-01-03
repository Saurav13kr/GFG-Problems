//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
         int left = 0, right = n-1;
        int left_max =0, right_max = 0;
        
        // Sum of Rain Water Trapped.
        long long sum = 0;
        
        while (left < right) {
            
            // Look On Left Side.
            if (arr[left] <= arr[right]) {
                
                if (arr[left] >= left_max)
                // Update Left Maximum. 
                    left_max = arr[left];
                    
                else
                // Water Can Be Stored.
                    sum += left_max - arr[left];
                
                // Increament Of Left Pointer.
                left ++;
            }
            
            // Look On Right Side.
            else {
                
                if (arr[right] >= right_max)
                // Update Right Maximum. 
                    right_max = arr[right];
                    
                else
                // Water Can Be Stored.
                    sum += right_max - arr[right];
                
                // Decreament Of Right Pointer.
                right --;
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends