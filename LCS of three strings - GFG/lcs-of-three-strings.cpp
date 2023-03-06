//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int solve(string &a, string &b, string &c, int n1, int n2, int n3,vector<vector<vector<int>>>&dp)
{
    
    if(n1<0 || n2<0 ||n3<0)
    return 0;
    if(dp[n1][n2][n3]!=-1)
    return dp[n1][n2][n3];
    if(a[n1]==b[n2] && b[n2]==c[n3])
    {
        return dp[n1][n2][n3]= 1+solve(a,b,c,n1-1,n2-1,n3-1,dp);
    }
    else
    return dp[n1][n2][n3]= max(solve(a,b,c,n1-1,n2,n3,dp),max(solve(a,b,c,n1,n2-1,n3,dp),solve(a,b,c,n1,n2,n3-1,dp)));
}

int LCSof3 (string a, string b, string c, int n1, int n2, int n3)
{
    vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
    return solve(a,b,c,n1-1,n2-1,n3-1,dp);
}