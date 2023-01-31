//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

int mod=1e9+7;
class Solution{
    public:
    
    int add(int a,int b)
    {
        return (a%mod+b%mod)%mod;
    }
    int multiply(int a,int b)
    {
        return ((a%mod)*1LL*(b%mod))%mod;
    }
    
    long long solve(int n,int k,vector<int>&dp)
    {
        if(n==1)
        return k;
        if(n==2)
        return add(multiply(k,k-1),k);
        if(dp[n]!=-1)
        return dp[n];
       int ans=add(multiply(solve(n-2,k,dp),k-1),multiply(solve(n-1,k,dp),k-1));
        return dp[n]=ans;
        
    }
    
    long long countWays(int n, int k){
        
        vector<int>dp(n+1,-1);
        return  solve(n,k,dp);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends