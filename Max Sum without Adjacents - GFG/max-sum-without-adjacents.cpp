//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	
	int fsum(vector<int>&dp,int* arr,int n)
	{
	    if(n<0)return 0;
	    if(n==0) 
	    return arr[0];
	    if(dp[n]!=-1)
	    return dp[n];
	    int inc=fsum(dp,arr,n-2)+ arr[n];
	    int exc=fsum(dp,arr,n-1);
	    dp[n]=max(inc,exc);
	    return dp[n];
	    
	}
	int findMaxSum(int *arr, int n) {
	    vector<int>dp(n+1,-1);
	    
	   int ans=fsum(dp,arr,n-1);
	   return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends