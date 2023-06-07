//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
		

	public:
	int solve(int arr[],int ind , int prev, int n,vector<vector<int>>& dp){
	    if(ind==n){
	        return 0;
	    }
	    if(dp[ind][prev+1]!=-1){
	        return dp[ind][prev+1];
	    }
	    int nottake = 0 + solve(arr,ind+1,prev,n,dp);
	    int take = 0;
	    if(prev==-1 || arr[ind]>arr[prev]){
	        take=arr[ind] + solve(arr,ind+1,ind,n,dp);
	    }
	    return dp[ind][prev+1]=max(take,nottake);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n,vector<int>(n+1,-1));
	    return solve(arr,0,-1,n,dp);
	}  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends