//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    
public:

    // int solve(int W,int wt[],int val[],int n,vector<vector<int>>&dp)
    // {
    //     if(W==0)
    //     return 0;
    //     if(n==0)
    //     {
    //         if(W>=wt[0])
    //         return val[0];
    //         return 0;
    //     }
    //     if(dp[n][W]!=-1)
    //     return dp[n][W];
    //     if(W>=wt[n])
    //     {
    //          return dp[n][W]= max(val[n]+solve(W-wt[n],wt,val,n-1,dp),solve(W,wt,val,n-1,dp));
    //     }
    //     if(wt[n]>W)
    //     {
    //         return dp[n][W]= solve(W,wt,val,n-1,dp);
    //     }
        
        
    // }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //   if(n==0)
    //   return 0;
    //   vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
    //   return solve(W,wt,val,n-1,dp);
        vector<vector<int>>t(n+1,vector<int>(W+1,-1));
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<W+1;j++)
            {
                if(i==0 || j==0)
                t[i][j]=0;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<W+1;j++)
        {
                 if(j>=wt[i-1])
            {
              t[i][j]= max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else
            {
             t[i][j]= t[i-1][j];
            }
        }
        }
        //for(int i=0;i<n+1;i++)
        //{
          //  for(int j=0;j<W+1;j++)
            //{
            //    cout<<t[i][j]<<" ";
            //}
            //cout<<endl;
        //}
        
        //cout<<t[n][W]<<endl;
        return t[n][W];
        
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