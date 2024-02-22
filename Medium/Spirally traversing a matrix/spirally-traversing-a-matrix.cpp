//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here
        vector<int>ans;
        
        int rowStart = 0;
        int rowEnd = r-1;
        int colStart = 0;
        int colEnd = c-1;
        
        int count = 0;
        int totalSize = r*c;
        while(count < totalSize){
            // 1st Row Print :
            for(int i=rowStart; i<=colEnd && count < totalSize; i++){
                ans.push_back(matrix[rowStart][i]);
                count++;
            }
            rowStart++;
            // last Column Print :
            for(int i=rowStart; i<=rowEnd && count < totalSize; i++){
                ans.push_back(matrix[i][colEnd]);
                count++;
            }
            colEnd--;
            // last Row Print :
            for(int i=colEnd; i>=colStart && count < totalSize; i--){
                ans.push_back(matrix[rowEnd][i]);
                count++;
            }
            rowEnd--;
            // 1st Column Print :
            for(int i=rowEnd; i>=rowStart && count < totalSize; i--){
                ans.push_back(matrix[i][colStart]);
                count++;
            }
            colStart++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends