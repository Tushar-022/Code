//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Functi
    
     void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>& grid,vector<pair<int,int>>&v, vector<vector<pair<int,int>>>&islands)
    {
          int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        
        vis[row][col]=1;
        v.push_back({row,col});
        q.push({row,col});
         //int delrow[]={-1,+1,0,0};
        //int delcol[]={0,0,+1,-1};
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
                q.pop();
            for(int delrow=-1;delrow<=1;delrow++)
            {
                for(int delcol=-1;delcol<=1;delcol++)
                {
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                
            
            
                
if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol]&&grid[nrow][ncol]==1)
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                    v.push_back({nrow,ncol});
                }
                }
            }
            
        }
    }

    
    int findMaxArea(vector<vector<int>>& grid) {
        
        
         int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<pair<int,int>>>islands;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>>v;
                    bfs(i,j,vis,grid,v,islands);
                    islands.push_back(v);   
                }
            }

        }
       // cout<<islands.size()<<endl;
        if(islands.size()==0)
        return 0;

        int maxi=islands[0].size();
        for(int i=1;i<islands.size();i++)
        {
            if(islands[i].size()>maxi)
            maxi=islands[i].size();
        }
         return maxi;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends