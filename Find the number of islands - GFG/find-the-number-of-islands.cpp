//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    // void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& grid)
    // {
    //     vis[row][col]=1;
    //     queue<pair<int,int>>q;
    //     q.push({row,col});
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     while(!q.empty())
    //     {
    //       int row=q.front().first;
    //       int col=q.front().second;
    //       q.pop();
    //       for(int delrow=-1;delrow<=1;delrow++)
    //       {
    //           for(int delcol=-1;delcol<=1;delcol++)
    //           {
    //               int nrow=row+delrow;
    //               int ncol=col+delcol;
    //              if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' 
    //              && !vis[nrow][ncol])
    //              {
    //                  vis[nrow][ncol]=1;
    //                  q.push({nrow,ncol});
    //              }
    //           }
    //       }
    //     }
        
    // }
    
    // int numIslands(vector<vector<char>>& grid) {
    //     // Code here
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     int cnt=0;
    //     vector<vector<int>>vis(n,vector<int>(m,0));
    //     for(int row=0;row<n;row++)
    //     {
    //         for(int col=0;col<m;col++)
    //         {
    //             if(!vis[row][col] && grid[row][col]=='1')
    //             {
    //                 cnt++;
    //                 bfs(row,col,vis,grid);
    //             }
    //         }
    //     }
    //     return cnt;
    // }
    void bfs(int &row,int &col,vector<vector<int>>&vis,vector<vector<char>>& grid,queue<pair<int,int>>&q)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        while(!q.empty())
        {
            auto node=q.front();
           // cout<<row<<" "<<col<<endl;
            int row=node.first;
            int col=node.second;
           // vis[row][col]=1;
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++)
            {
                for(int delcol=-1;delcol<=1;delcol++)
                {
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]=='1' && !vis[nrow][ncol])
                    {
                        //cout<<nrow<<" "<<ncol<<endl;
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m+1,vector<int>(n+1,0));
        queue<pair<int,int>>q;
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                  //  cout<<i<<" "<<j<<endl;
                    vis[i][j]=1;
                    ans++;
                    q.push({i,j});
                    bfs(i,j,vis,grid,q);
                }
            }
        }
        return ans;
    }
};
//};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends