//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int cntremovals(vector<int>&arr,vector<vector<int>>&dp,int i,int j,int k)
    {
        if(i>j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(arr[j]-arr[i]<=k)
        return 0;
        else if(arr[j]-arr[i]>k)
        {
            dp[i][j]=1+min(cntremovals(arr,dp,i+1,j,k),cntremovals(arr,dp,i,j-1,k));
        }
        return dp[i][j];
    }
    
    int removals(vector<int>& arr, int k){
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        if(n==1)
        return 0;
        else
        return cntremovals(arr,dp,0,n-1,k);
      
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends