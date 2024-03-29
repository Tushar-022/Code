//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    long long m=1e9+7;
    long long int fib(vector<long long int >&dp,long long int n)
    {
        if(n<=1)
        return n;
        if(dp[n]!=-1)
        return dp[n];
        dp[n]=(fib(dp,n-1)+fib(dp,n-2)) % m;
        return dp[n];
    }
    long long int nthFibonacci(long long int n){
        vector<long long int>dp(n+1,-1);
       return fib(dp,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends