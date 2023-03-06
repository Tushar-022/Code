//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

int lcs(string &s ,string &t,int n1,int n2,vector<vector<int>>&dp)
{
    if(n1<0 || n2<0)
    return 0;
    if(dp[n1][n2]!=-1)
    return dp[n1][n2];
    if(s[n1]==t[n2])
    return dp[n1][n2]= 1+lcs(s,t,n1-1,n2-1,dp);
    else
    return  dp[n1][n2]=max(lcs(s,t,n1-1,n2,dp),lcs(s,t,n1,n2-1,dp));
}
int minDeletions(string s, int n) { 
    string t=s;
    reverse(s.begin(),s.end());
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return n-lcs(s,t,n-1,n-1,dp);
    
} 