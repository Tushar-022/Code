//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void dfs(int row,int col,vector<vector<char>>&mat,vector<vector<int>>&vis)
    {
        vis[row][col]=1;
        int m=mat.size();
        int n=mat[0].size();
        int delrow[]={0,0,-1,+1};
        int delcol[]={+1,-1,0,0};
        
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && !vis[nrow][ncol] && mat[nrow][ncol]=='O')
            {
                vis[nrow][ncol]=1;
                dfs(nrow,ncol,mat,vis);
            }
        }
        
        
    }

    vector<vector<char>> fill(int m, int n, vector<vector<char>> mat)
    {
        
        
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            if(mat[i][0]=='O' && !vis[i][0])
            dfs(i,0,mat,vis);
            
            if(mat[i][n-1]=='O' && !vis[i][n-1])
            dfs(i,n-1,mat,vis);
        }
        
        for(int j=0;j<n;j++)
        {
            if(mat[0][j]=='O' && !vis[0][j])
            dfs(0,j,mat,vis);
            
            if(mat[m-1][j]=='O' && !vis[m-1][j])
            dfs(m-1,j,mat,vis);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]=='O' && !vis[i][j])
                mat[i][j]='X';
            }
        }
        return mat;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends