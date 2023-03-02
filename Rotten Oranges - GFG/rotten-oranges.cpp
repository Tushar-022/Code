//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>>ans=grid;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ans[i][j]==2)
                {
                    q.push({{i,j},0});
                }
            }
        }
        int tm=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        while(!q.empty())
        {
            auto node=q.front();
            int row=node.first.first;
            int col=node.first.second;
            int t=node.second;
            q.pop();
            tm=max(t,tm);
            for(int i=0;i<4;i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && ans[nrow][ncol]==1 )
                {
                    q.push({{nrow,ncol},t+1});
                    ans[nrow][ncol]=2;
                }
            }
        }
            for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ans[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return tm;
        
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends