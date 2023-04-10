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
        vector<vector<int>>dp(n,vector<int>(tsum+1,0));
        for(int i=0;i<n;i++)
        dp[i][0]=1;
        
       // if(tsum>=arr[0])
        dp[0][arr[0]]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<tsum+1;j++)
            {
                bool not_take=dp[i-1][j];
                bool take=false;
                if(j>=arr[i])
                take=dp[i-1][j-arr[i]];
                dp[i][j]=take|not_take;
            }
        }
        int mini=INT_MAX;
        for(int j=0;j<=tsum/2;j++)
        {
            if(dp[n-1][j]==1)
            mini=min(mini,abs(tsum-2*j));
        }
        return mini;
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