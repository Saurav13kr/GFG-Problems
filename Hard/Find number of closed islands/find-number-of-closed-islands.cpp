//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void bfs(vector<vector<int>> &vis,vector<vector<int>> &matrix,queue<pair<int,int>> &q)
    {   int a=matrix.size();
        int b=matrix[0].size();
        while(q.empty()==false)
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<a && nc>=0 && nc<b && matrix[nr][nc]==1 && vis[nr][nc]==0)
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    
    void bfsq(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &matrix)
    {   int a=matrix.size();
        int b=matrix[0].size();
        vis[i][j]=1;
        queue<pair<int,int>> qq;
        qq.push({i,j});
        while(qq.empty()==false)
        {
            int r=qq.front().first;
            int c=qq.front().second;
            qq.pop();
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int x=0;x<4;x++)
            {
                int nr=r+dr[x];
                int nc=c+dc[x];
                if(nr>=0 && nr<a && nc>=0 && nc<b && matrix[nr][nc]==1 && vis[nr][nc]==0)
                {
                    vis[nr][nc]=1;
                    qq.push({nr,nc});
                }
            }
        }
    }
    
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        vector<vector<int>> vis(N,vector<int>(M,0));
        queue<pair<int,int>> q;
        for(int i=0;i<N;i++)
        {
            if(matrix[i][0]==1)
            {
                vis[i][0]=1;
                q.push({i,0});
            }
            if(matrix[i][M-1]==1)
            {
                vis[i][M-1]=1;
                q.push({i,M-1});
            }
            
        }
        for(int i=0;i<M;i++)
        {
            if(matrix[0][i]==1)
            {
                vis[0][i]=1;
                q.push({0,i});
            }
            if(matrix[N-1][i]==1)
            {
                vis[N-1][i]=1;
                q.push({N-1,i});
            }
        }
        
        bfs(vis,matrix,q);
        int c=0;
        for(int p=0;p<N;p++)
        {
            for(int q=1;q<M;q++)
            {
                if(vis[p][q]==0 && matrix[p][q]==1)
                {
                    bfsq(p,q,vis,matrix);
                    c++;
                }
            }
        }
        return c;
        // Code here
    }
};



//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends