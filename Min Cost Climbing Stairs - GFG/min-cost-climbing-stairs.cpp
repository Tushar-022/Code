//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
      int  paisa(vector<int>&dp,vector<int>&cost,int n)
        {
                if(n==0)
                return cost[0];
                if(n==1)
                return cost[1];
        
        if(dp[n]!=-1)
        return dp[n];
        dp[n]=min(paisa(dp,cost,n-1),paisa(dp,cost,n-2))+cost[n];
        return dp[n];
        }
    
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
       return min(paisa(dp,cost,n-1),paisa(dp,cost,n-2));
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends