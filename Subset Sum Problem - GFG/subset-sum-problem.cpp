//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // bool solve(vector<int>&arr, int sum,int n,vector<vector<int>>dp)
    // {
    //     if(n==0 )
    //     {
    //         if(sum==arr[0])
    //         return true;
    //         return false;
    //     }
    //     if(sum==0)
    //     return true;
    //     if(dp[n][sum]!=-1)
    //     return dp[n][sum];
    //     return dp[n][sum]=(solve(arr,sum-arr[n],n-1,dp)|| solve(arr,sum,n-1,dp));
        
    //}

    bool isSubsetSum(vector<int>arr, int sum){
        
        int n=arr.size();
     vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    //return solve(arr,sum,n-1,dp);
    for(int j=0;j<sum+1;j++)
    dp[0][j]=0;
    
    for(int i=0;i<n+1;i++)
    dp[i][0]=1;
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j>=arr[i-1])
            dp[i][j]=(dp[i-1][j-arr[i-1]]|| dp[i-1][j]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    // for(int i=0;i<n+1;i++)
    // {
    //     for(int j=0;j<sum+1;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[n][sum];
    
    
    
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends