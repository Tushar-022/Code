//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int row,int col,int m,int n,vector<vector<int>>&mat,vector<vector<int>>&dp)
    {
        if(row>=m || row<0 || col>=n)
        return INT_MIN;
        
        if(col==n-1)
        return mat[row][col];
        
        if(dp[row][col]!=-1)
        return dp[row][col];
        
        int rud=solve(row-1,col+1,m,n,mat,dp);
        int rld=solve(row+1,col+1,m,n,mat,dp);
        int r=solve(row,col+1,m,n,mat,dp);
        return dp[row][col]= max(rud,max(rld,r))+mat[row][col];
    }
    int maxGold(int m, int n, vector<vector<int>>mat)
    {
        int ans=0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<m;i++)
        {
             ans=max(ans,solve(i,0,m,n,mat,dp));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends