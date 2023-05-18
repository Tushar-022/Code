//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


//User function Template for C++

class Solution {
    public:
    bool isvalid(int i,int j,int n,int m){
        if(i>=0 && i<n && j>=0 && j<m){
            return true;
        }
        return false;
    }
    void dfs(int i,int j,int n,int m,vector<vector<int>>&matrix){
        matrix[i][j]=0;
        vector<int>dr={0,1,0,-1};
        vector<int>dc={1,0,-1,0};
        for(int k=0;k<4;k++){
            int ni=i+dr[k];
            int nj=j+dc[k];
            if(isvalid(ni,nj,n,m)  && matrix[ni][nj]==1){
                dfs(ni,nj,n,m,matrix);
            }
        }
    }
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        
        for(int i=0;i<n;i++){
            if(matrix[i][0]==1){
                dfs(i,0,n,m,matrix);
            }
        }
        for(int i=0;i<n;i++){
            if(matrix[i][m-1]==1){
                dfs(i,m-1,n,m,matrix);
            }
        }
        for(int i=0;i<m;i++){
            if(matrix[0][i]==1){
                dfs(0,i,n,m,matrix);
            }
        }
        for(int i=0;i<m;i++){
            if(matrix[n-1][i]==1){
                dfs(n-1,i,n,m,matrix);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    count++;
                    dfs(i,j,n,m,matrix);
                }
            }
        }
        return count;
    }
};



//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends