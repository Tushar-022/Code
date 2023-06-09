//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
 public:
	int minDifference(int arr[], int n)  { 
        int tsum=0;
        for(int i=0;i<n;i++)
        {
            tsum+=arr[i];
        }
        int tgt=tsum;
        //vector<vector<int>>dp(n,vector<int>(tsum+1,0));
         vector<vector<int>>dp(n+1,vector<int>(tgt+1,0));
        
        for(int i=0;i<n;i++)
        {
           dp[i][0]=1;
        }
        if(tsum>=arr[0])
        dp[0][arr[0]]=1;
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=tgt;j++)
            {
                int ntake=dp[i-1][j];
                int take=false;
                if(j>=arr[i])
                {
                    take=dp[i-1][j-arr[i]];
                }
                dp[i][j]=take|ntake;
            }
        }
       // return dp[n-1][tgt];
        int ans=INT_MAX;
        for(int i=0;i<=tgt;i++)
        {
         if(dp[n-1][i]==1)
         ans=min(ans,abs(tgt-2*i));
        }
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
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends