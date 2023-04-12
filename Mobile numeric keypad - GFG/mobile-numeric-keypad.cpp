//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//class Solution{


// 	public:
	
// 	int mod=1e9+7;
// 	 long long solve(int val,int n,vector<vector<int>>&v,vector<vector<int>>&dp)
//     {
//         if(n<=1)
//         return n;
//         long long ans=0;
//         if(dp[n][val]!=-1)
//         return dp[n][val];
//         for(int i=0;i<v[val].size();i++)
//         {
//             ans+=solve(v[val][i],n-1,v,dp);
//         }
//         return dp[n][val]=ans;
//     }
// 	long long getCount(int n)
// 	{
// 		vector<vector<int>>m(10);
// 		vector<vector<int>>dp(n+1,vector<int>(10,-1));
// 		m[0]={0,8};
// 		m[1]={1,2,4};
// 		m[2]={1,2,3,5};
// 		m[3]={2,3,6};
// 		m[4]={1,4,7,5};
// 		m[5]={2,4,6,8,5};
// 		m[6]={3,9,5,6};
// 		m[7]={4,7,8};
// 		m[8]={5,7,8,9,0};
// 		m[9]={6,8,9};
		
// 		long long ans=0;
// 		for(int i=0;i<10;i++)
//         {
//             ans+=solve(i,n,m,dp);
//           // ans%=mod;
//         }
        
// 		return ans;
// 	}

class Solution{


	public:
	long long int dfs(int index,int N,unordered_map<int,vector<int>> & adj,vector<vector<long long int>> &dp){
	    if(N==1)return 1;
	    if(dp[N][index]!=-1)return dp[N][index];
	    long long int ans=0;
	    for(auto it:adj[index]){
	        ans+=dfs(it,N-1,adj,dp);
	    }
	    return dp[N][index]=ans;
	}
	long long getCount(int N)
	{
		// Your code goes here
		unordered_map<int,vector<int>> adj;
		adj[0]={0,8};
		adj[1] = {2,4,1};
		adj[2] = {1,3,5,2};
		adj[3] = {2,6,3};
		adj[4] = {1,5,7,4};
		adj[5] = {2,4,6,8,5};
		adj[6] = {3,5,9,6};
		adj[7] = {4,8,7};
		adj[8] = {5,7,9,0,8};
		adj[9] = {6,8,9};
		long long int ans=0;
		vector<vector<long long int>> dp(N+1,vector<long long int>(10,-1));
		for(int i=0;i<=9;i++){
		    ans+=dfs(i,N,adj,dp);
		}
		return ans;
	}


};



//};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends