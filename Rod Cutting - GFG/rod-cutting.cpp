//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
        //int cost;
        int solve(int len,int * price,int ind,int cost,vector<vector<int>>&dp)
        {
            if(len<=0)
            return 0;
            
            if(ind==0)
            {
                while(len!=0)
                {
                    len=len-1;
                    cost+=price[0];
                }
                //cout<<cost<<endl;
                return dp[ind][len]=cost;
            }
            
            if(dp[ind][len]!=-1)
            return dp[ind][len];
            int npick=solve(len,price,ind-1,cost,dp);
            int pick=false;
            if(len>=ind+1)
            {
                pick=max(price[ind]+solve(len-ind-1,price,ind,cost,dp),price[ind]+solve(len-ind-1,price,ind-1,cost,dp));
            }
            return dp[ind][len]=max(pick,npick);
            
        }
    int cutRod(int price[], int n) {
        int cost=0;
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return solve(n,price,n-1,cost,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends