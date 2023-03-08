//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    // int solve(vector<vector<int>>& grid,vector<vector<int>>&vis,vector<vector<int>>&dp,int i,int j)
    // {
    //     if(i==0 && j==0)
    //     return grid[i][j];
    //     int delrow[]={-1,0,1,0};
    //     int delcol[]={0,1,0,-1);
    //     for(int i=0;i<4;i++)
    //     {
    //         int nrow=+delrow[i];
    //         int ncol=
    //     }
    // }
   //using pair<int,int>=pi;
    int minimumCostPath(vector<vector<int>>& a) 
    {
        // int m=grid.size();
        // int n=grid[0].size();
        
        // vector<vector<int>>vis(m+1,vector<int>(n+1,0));
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // return solve(grid,vis,dp,m,n);
        

// class Solution
// {
//     public:
//     //Function to return the minimum cost to react at bottom
// 	//right cell from top left cell.
    // int minimumCostPath(vector<vector<int>>& a) 
    // {
        int n=a.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({a[0][0],{0,0}});//cost,row,col
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        while(pq.size()){
            auto it=pq.top();
            int row=it.second.first;
            int col=it.second.second;
            int ans=it.first;
            pq.pop();
            if(row==n-1 and col==n-1)return ans;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    pq.push({ans+a[nrow][ncol],{nrow,ncol}});
                }
            }
        }
    }
};
//     }
// };

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends