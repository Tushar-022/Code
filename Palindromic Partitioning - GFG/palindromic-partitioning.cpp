//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
        
    bool ispal(int i,int j,string s)
    {
        while(j>i)
        {
            if(s[i++]!=s[j--])
            return false;
        }
        return true;
    }
    
    int solve(int i,int j,string s,int n,vector<vector<int>>&dp)
    {
        if(i>=j)
        return 0;
        if(ispal(i,j,s))
        return 0;
        int partitions=INT_MAX;
        if(dp[i][j]!=-1)
        return dp[i][j];
        for(int k=i;k<j;k++)
        {
            //int par=solve(i,k,s,n,dp)+solve(k+1,j,s,n,dp)+1;
        int left=0,right=0;
        if(dp[i][k]!=-1)
        left= dp[i][k];
        else
        {
            left=solve(i,k,s,n,dp);
            dp[i][k]=left;
        }
        if(dp[k+1][j]!=-1)
        right=dp[k+1][j];
        else
        {
        right=solve(k+1,j,s,n,dp);
        dp[k+1][j]=right;
        }
        int par=left+right+1;
            
            partitions=min(par,partitions);
        }
        return dp[i][j]=partitions;
    }

    int palindromicPartition(string s)
    {
        int n=s.length();
        if(n==1)
        return 0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,s,n,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends