//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
 //User function Template for C++
class Solution{
public:
    bool check(int i,vector<int>&arr,vector<int>&vis,vector<int>&dp){
    
    if(i>=arr.size() ) return 1;
    if(vis[i]==1)return 0;
    if(dp[i]!=-1)return dp[i];
    vis[i]=1;
    
    bool f =  check(i+arr[i],arr,vis,dp);
    vis[i]=0;
    
    return dp[i] = f;
    
}
    int goodStones(int n,vector<int> &arr){
        // Code here
        vector<int>vis(n,0);
        vector<int>dp(n,-1);
        int res = 0;
        for(int i = 0;i<n;i++){
          
            bool f = check(i,arr,vis,dp);
           
            if(f)res++;
            
        }
        return res;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends