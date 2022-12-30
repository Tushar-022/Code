//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    
     void dfs(int row,int col, vector<vector<int>>&vis, vector<vector<int>>&grid)
  {
     int m=grid.size();
        int n=grid[0].size();
    vis[row][col]=1;
    int delrow[]={-1,+1,0,0};
    int delcol[]={0,0,-1,+1};

    for(int i=0;i<4;i++)
    {
      int nrow=row+delrow[i];
      int ncol=col+delcol[i];

      if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && !vis[nrow][ncol] && grid[nrow][ncol]==1)
      {
        vis[nrow][ncol]=1;
        dfs(nrow,ncol,vis,grid);
      }

    }
  }
    
    int closedIslands(vector<vector<int>>& grid, int m, int n) {
        
         vector<vector<int>>vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
          if(grid[i][0]==1 && !vis[i][0])
          dfs(i,0,vis,grid);

          if(grid[i][n-1]==1 && !vis[i][n-1])
          dfs(i,n-1,vis,grid);
        }

        for(int j=0;j<n;j++)
        {
          if(grid[0][j]==1 && !vis[0][j])
          dfs(0,j,vis,grid);

          if(grid[m-1][j]==1 && !vis[m-1][j])
          dfs(m-1,j,vis,grid);
        }

        int cnt=0;
        for(int i=0;i<m;i++)
        {
          for(int j=0;j<n;j++)
          {
            if(grid[i][j]==1 && !vis[i][j])
            {
              dfs(i,j,vis,grid);
              cnt++;
            }
          }
        }
        return cnt;
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