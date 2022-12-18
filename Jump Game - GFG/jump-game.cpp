//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  bool solve(int*A,int i,int n,vector<int>&dp)
        {
            if(i==n-1)
            return true;
            if(dp[i]!=-1)
            return dp[i];
                for(int j=1;j<=A[i];j++)
                {
                    if(solve(A,i+j,n,dp))
                    return dp[i]=true;
                }
                return dp[i]= false;
         }
    int canReach(int A[], int N) {
         // n=nums.size();
        if(N==1)
        return true;
        if(A[0]==0)
        return false;
        vector<int>dp(N,-1);
      return  solve(A,0,N,dp);
    }
};



    //bool canJump(vector<int>& nums) {
        
       
    //}
//};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends