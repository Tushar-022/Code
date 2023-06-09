//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    // int solve(vector<int>&arr, int tgt,int ind)
    // {
    //     if(tgt==0)
    //     return true;
    //     if(ind==0)
    //     {
    //         if(tgt!=arr[0])
    //         return false;
    //         return true;
    //     }
        
    //     int ntake=solve(arr,tgt,ind-1);
    //     int take=false;
    //     if(tgt>=arr[ind])
    //      take=solve(arr,tgt-arr[ind],ind-1);
         
    //      return take|ntake;
    // }
    bool isSubsetSum(vector<int>arr, int tgt){
        
        // return solve(arr,tgt,arr.size()-1); 
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(tgt+1,0));
        
        for(int i=0;i<n;i++)
        {
           dp[i][0]=1;
        }
        if(tgt>=arr[0])
        dp[0][arr[0]]=1;
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=tgt;j++)
            {
                int ntake=dp[i-1][j];
                int take=false;
                if(j>=arr[i])
                {
                    take=dp[i-1][j-arr[i]];
                }
                dp[i][j]=take|ntake;
            }
        }
        return dp[n-1][tgt];
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