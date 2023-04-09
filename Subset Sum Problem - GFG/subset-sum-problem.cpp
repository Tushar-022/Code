//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

     bool solve(vector<vector<int>>&dp,vector<int>&arr,int sum,int ind)
     {
         if(sum==0)
         return true;
         if(ind==0)
         return (sum==arr[ind]);
         if(dp[ind][sum]!=-1)
         return dp[ind][sum];
         bool not_take=solve(dp,arr,sum,ind-1);
         bool take=false;
         if(sum>=arr[ind])
         take=solve(dp,arr,sum-arr[ind],ind-1);
         return dp[ind][sum]=take|not_take;
         
         
     }
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(dp,arr,sum,n-1);
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