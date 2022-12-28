//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
        
        void dfs( int sr, int sc, int inicolor,int newcolor,vector<vector<int>>&ans,vector<vector<int>>&image,int*delrow,int*delcol)
        {
            ans[sr][sc]=newcolor;
            int m=ans.size();
            int n=ans[0].size();
            for(int i=0;i<4;i++)
            {
                int nrow=sr+delrow[i];
                int ncol=sc+delcol[i];
                if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && ans[nrow][ncol]!=newcolor && image[nrow][ncol]==inicolor)
                {
                    dfs(nrow,ncol,inicolor,newcolor,ans,image,delrow,delcol);
                }
            }
            
        }
        
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
    
    int inicolor=image[sr][sc];
    vector<vector<int>>ans=image;
    int delrow[]={-1,0,+1,0};
    int delcol[]={0,+1,0,-1};
    dfs(sr,sc,inicolor,newcolor,ans,image,delrow,delcol);
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