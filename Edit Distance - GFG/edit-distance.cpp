//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int solve(int i,int j,string s,string t,vector<vector<int>>&dp)
  {
      if(i<0)
      return j+1;
      if(j<0)
      return i+1;
      if(dp[i][j]!=-1)
      return dp[i][j];
      if(s[i]==t[j])
      return dp[i][j]=solve(i-1,j-1,s,t,dp);
      else
      {
         return dp[i][j]=1+min(solve(i,j-1,s,t,dp),min(solve(i-1,j,s,t,dp),solve(i-1,j-1,s,t,dp)));
         
      }
  }
    int editDistance(string s, string t) {
        
    int m=s.length();
    int n=t.length();
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
     return  solve(m-1,n-1,s,t,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends