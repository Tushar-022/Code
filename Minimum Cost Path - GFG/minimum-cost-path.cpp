//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int minimumCostPath(vector<vector<int>>&grid) 
    {
        
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});//cost,row,col
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        while(pq.size()){
            auto it=pq.top();
            int cost=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            pq.pop();
            if(row==n-1 and col==n-1)
            return cost;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    pq.push({cost+grid[nrow][ncol],{nrow,ncol}});
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