//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  
  int solve(int i,int buy,int*A,int m,vector<vector<vector<int>>>&dp,int cap)
    {
        if(i==m|| cap==0)
        return 0;
        if(dp[i][buy][cap]!=-1)
        return dp[i][buy][cap];
        if(buy)
        { return dp[i][buy][cap]= max(-A[i]+
        solve(i+1,0,A,m,dp,cap),solve(i+1,1,A,m,dp,cap));
        }
        else
        {
            return dp[i][buy][cap]= max(A[i]+
            solve(i+1,1,A,m,dp,cap-1),solve(i+1,0,A,m,dp,cap));
        }
    }
  
  
    int maxProfit(int K, int N, int A[]) {
       int m=N;
        int i=0;
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(2,vector<int>(K+1,-1)));
        return solve(0,1,A,m,dp,K); 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends