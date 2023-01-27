//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int mod=1e9+7;
	
	int solve(string s,vector<int>&dp,int index)
	{
	    if(index==s.length())
	    return 1;
	    if(s[index]=='0')
	    return 0;
	    if(dp[index]!=-1)
	    return dp[index];
	    
	   long long  cnt=solve(s,dp,index+1)%mod;
	    if(index+1<s.size()  && (s[index]<'2'|| (s[index]<='2' && s[index+1]<='6')))
	    {
	        cnt+=solve(s,dp,index+2);
	        cnt=cnt%mod;
	    }
	    return dp[index]=cnt%mod;
	}
	
		int CountWays(string s){
		    
		    vector<int>dp(s.length(),-1);
		    return solve(s,dp,0);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends