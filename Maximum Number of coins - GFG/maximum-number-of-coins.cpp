//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
     int solve(int i,int j,vector<int> &nums,vector<vector<int>>&dp)
        {
            if(i>j)
            return 0;
            
            int maxi=INT_MIN;
            if(dp[i][j]!=-1)
            return dp[i][j];
            for(int k=i;k<=j;k++)
            {
                int steps=nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums,dp)+solve(k+1,j,nums,dp);
                maxi=max(steps,maxi);
            }
            return  dp[i][j]=maxi;
        }

        int maxCoins(int N, vector <int> & nums)
        {
               //  int N=nums.size();
            nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        return solve(1,N,nums,dp);
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends