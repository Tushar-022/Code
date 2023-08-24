//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    
    
    int solve(int ind,int spaces,int k,int n,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(ind==n)
        return 0;
        
        if(dp[ind][spaces+1]!=-1)
        return dp[ind][spaces+1];
        
        if(spaces>=nums[ind])
        {
            return dp[ind][spaces+1] = min(solve(ind+1,spaces-nums[ind]-1,k,n,nums,dp),(spaces+1)*(spaces+1)+solve(ind+1,k-nums[ind]-1,k,n,nums,dp));
        }
        
        return dp[ind][spaces+1] = (spaces+1)*(spaces+1)+solve(ind+1,k-nums[ind]-1,k,n,nums,dp);
        
        
    }
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n=nums.size();
        vector<vector<int>>dp(n+2,vector<int>(k+2,-1));
        return solve(0,k,k,n,nums,dp);
    } 
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends