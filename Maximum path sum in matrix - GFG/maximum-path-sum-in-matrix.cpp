//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
       int  solve(int i,int j,vector<vector<int>> &Matrix,vector<vector<int>> &dp)
        {
            
            if(j<0 || j>=Matrix[0].size())
            return -1e9;
            if(i==0)
            return Matrix[0][j];
            if(dp[i][j]!=-1)
            return dp[i][j];
                int up=Matrix[i][j]+solve(i-1,j,Matrix,dp);
                int rd=Matrix[i][j]+solve(i-1,j+1,Matrix,dp);
                int ld=Matrix[i][j]+solve(i-1,j-1,Matrix,dp);
                dp[i][j]=max(up,max(rd,ld));
                return dp[i][j];
            
        }
    
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int maxi=-1e8;
        vector<vector<int>>dp(N,vector<int>(N,-1));
        for(int j=0;j<N;j++)
        {
            maxi=max(maxi,solve(N-1,j,Matrix,dp));
        }
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