//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       
       int m=image.size();
       int n=image[0].size();
       int inicolor=image[sr][sc];
       vector<vector<int>>vis(m,vector<int>(n,0));
       vector<vector<int>>ans=image;
       queue<pair<int,int>>q;
       int delrow[]={-1,0,1,0};
       int delcol[]={0,1,0,-1};
       q.push({sr,sc});
       vis[sr][sc]=1;
       
       while(!q.empty())
       {
           auto node=q.front();
           int row=node.first;
           int col=node.second;
           ans[row][col]=newColor;
           q.pop();
           for(int i=0;i<4;i++)
           {
               int nrow=row+delrow[i];
               int ncol=col+delcol[i];
               if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && !vis[nrow][ncol] && image[nrow][ncol]==inicolor  )
               {
                   q.push({nrow,ncol});
                   vis[nrow][ncol]=1;
               }
           }
           
           
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends