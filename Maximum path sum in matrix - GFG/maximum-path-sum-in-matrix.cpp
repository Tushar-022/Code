//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
       //int  solve(int i,int j,vector<vector<int>> &Matrix,vector<vector<int>> &dp)
        // {
            
        //     if(j<0 || j>=Matrix[0].size())
        //     return -1e9;
        //     if(i==0)
        //     return Matrix[0][j];
        //     if(dp[i][j]!=-1)
        //     return dp[i][j];
        //         int up=Matrix[i][j]+solve(i-1,j,Matrix,dp);
        //         int rd=Matrix[i][j]+solve(i-1,j+1,Matrix,dp);
        //         int ld=Matrix[i][j]+solve(i-1,j-1,Matrix,dp);
        //         dp[i][j]=max(up,max(rd,ld));
        //         return dp[i][j];
            
        // }
    
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // int maxi=-1e8;
        // vector<vector<int>>dp(N,vector<int>(N,-1));
        // for(int j=0;j<N;j++)
        // {
        //     maxi=max(maxi,solve(N-1,j,Matrix,dp));
        // }
        // return maxi;
        int t[N][N];
        for(int j=0;j<N;j++)
        t[0][j]=Matrix[0][j];
        
        for(int i=1;i<N;i++)
        {
          for(int j=0;j<N;j++)
            {
             int down=Matrix[i][j],ld=Matrix[i][j],rd=Matrix[i][j];
            down+=t[i-1][j];
            if(j>0)
            ld+=t[i-1][j-1];
            else
            ld+=-1e9;
            if(j+1<N)
            rd+=t[i-1][j+1];
            else
            rd+=-1e9;
            t[i][j]=max(down,max(ld,rd));
            }
          }
        int maxi=-1e8;
        for(int j=0;j<N;j++)
        maxi=max(maxi,t[N-1][j]);
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends