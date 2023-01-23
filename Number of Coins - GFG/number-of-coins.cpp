//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int solve(int* coins,int index,int v,vector<vector<int>>&dp)
	{
	    if(index==0 )
	    {
	        if(v%coins[0]==0)
	        return v/coins[0];
	        else
	        return 1e9;
	    }
	    if(dp[index][v]!=-1)
	    return dp[index][v];
	    int notpick=solve(coins,index-1,v,dp);
	    int pick=INT_MAX;
	    if(coins[index]<=v)
	    {
	        pick=1+solve(coins,index,v-coins[index],dp);
	    }
	    return dp[index][v]= min(pick,notpick);
	    
	}
	
	
	int minCoins(int coins[], int n, int v) 
	{ 
	    vector<vector<int>>dp(n,vector<int>(v+1,-1));
	    int ans= solve(coins,n-1,v,dp);
	    if(ans>=1e9)
	    return -1;
	    else
	    return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends