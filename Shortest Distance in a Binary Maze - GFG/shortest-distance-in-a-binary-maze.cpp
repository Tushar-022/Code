//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

typedef pair<int,int>pii;
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
         int m=grid.size();
         int n=grid[0].size();
         int row=source.first;
         int col=source.second;
         int endrow=destination.first;
         int endcol=destination.second;
        // vector<vector<int>>distance()
        vector<vector<int>>distance(m,vector<int>(n,1e9));

        queue<pair<pair<int,int>,int>>q;
        q.push({{row,col},0});
        distance[row][col]=0;
        
        int delrow[]={-1,1,0,0};
        int delcol[]={0,0,-1,1};
        
if(source.first==destination.first && source.second==destination.second) 
    return 0; 
        while(!q.empty())
        {
            int rrow=q.front().first.first;
            int ccol=q.front().first.second;
            int steps=q.front().second;
            q.pop();
        for(int i=0;i<4;i++)
          {
            //for(int j=-1;j<=1;j++)
            //{
                int nrow=rrow+delrow[i];
                int ncol=ccol+delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && steps+1<distance[nrow][ncol])
                {
                    
                    distance[nrow][ncol]=1+steps;
                    if(nrow==destination.first && ncol==destination.second)
                    return steps+1;
                    q.push({{nrow,ncol},steps+1});
                    
                }
            }
          }
        //}
        return -1;
        
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends