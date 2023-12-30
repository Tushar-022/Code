//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int wt,int* w,int* val,int ind,vector<vector<int>>&dp)
    {
        if(wt<0 ||ind<0)
        return 0;
        
        if(dp[ind][wt]!=-1)
        return dp[ind][wt];
        
        int npick=solve(wt,w,val,ind-1,dp);
        int pick=0;
        if(wt>=w[ind])
        {
            pick=val[ind]+solve(wt-w[ind],w,val,ind-1,dp);
        }
        return dp[ind][wt]= max(pick,npick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return solve(W,wt,val,n-1,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends