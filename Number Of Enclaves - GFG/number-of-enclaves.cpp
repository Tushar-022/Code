//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        vis[row][col]=1;
        int m=grid.size();
        int n=grid[0].size();
        int delrow[]={0,0,-1,+1};
        int delcol[]={+1,-1,0,0};
        
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            {
                vis[nrow][ncol]=1;
                dfs(nrow,ncol,grid,vis);
            }
        }
        
        
    }

  
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int m=grid.size();
        int n=grid[0].size();
         vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1 && !vis[i][0])
            dfs(i,0,grid,vis);
            
            if(grid[i][n-1]==1  && !vis[i][n-1])
            dfs(i,n-1,grid,vis);
        }
        
        int cnt=0;
        
        for(int j=0;j<n;j++)
        {
            if(grid[0][j]==1 && !vis[0][j])
            dfs(0,j,grid,vis);
            
            if(grid[m-1][j]==1 && !vis[m-1][j])
            dfs(m-1,j,grid,vis);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                //mat[i][j]='X';
                cnt++;
                
            }
        }
        return cnt;
        
    }
        
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends