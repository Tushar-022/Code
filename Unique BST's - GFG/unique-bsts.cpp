//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
        int mod=1e9+7;
       long long solve(int n,vector<int>&dp)
    {
        if(n<=1)
        return 1;
        if(dp[n]!=-1)
        return dp[n];
        long long ans=0;
       // cout<<ans<<endl;
        for(int i=1;i<n+1;i++)
        {
          //  cout<<ans<<endl;
           // ans+=(solve(i-1,dp)* solve(n-i,dp));
            ans=ans%mod+((solve(i-1,dp)%mod)*(solve(n-i,dp)%mod))%mod;
        }
        return dp[n]=ans%mod;

    }
    
    int numTrees(int n) 
    {
        vector<int>dp(n+1,-1);
        return (solve(n,dp));
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	
// } Driver Code Ends