//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int row,int col,vector<pair<int,int>>&v,vector<vector<int>>&vis,vector<vector<int>>& grid,int row0,int col0)
    {
        int m=grid.size();
        int n=grid[0].size();
        vis[row][col]=1;
        v.push_back({row-row0,col-col0});
        int delrow[]={-1,+1,0,0};
        int delcol[]={0,0,+1,-1};
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            {
               // vis[nrow][ncol]=1;
                dfs(nrow,ncol,v,vis,grid,row0,col0);
            }
        }
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n,0));
        set<vector<pair<int,int>>>s;
        
        
        for(int i= 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if( !vis[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>>v;
                    dfs(i,j,v,vis,grid,i,j);
                    s.insert(v);
                }
            }
        }
        return s.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends