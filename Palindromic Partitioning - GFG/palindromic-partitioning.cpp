//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

bool ispal(int i,int j,string&s)
    {
        while(j>i)
        {
            if(s[i++]!=s[j--])
            {
                return false;
            }
        }
        return true;
    }
    
     int solve(int i,int j,string &s,vector<int>&dp)
    {
    if(i>=j)
    return 0;
    if(ispal(i,j,s))
     return 0;
    int partitions=INT_MAX,cost=0;
    if(dp[i]!=-1)
    return dp[i];
    for(int k=i;k<j;k++)
    {
        if(ispal(i,k,s))
        {
            cost=1+solve(k+1,j,s,dp);
        
            partitions=min(partitions,cost);
        }
    }
    return dp[i]=partitions;

}
    int palindromicPartition(string s)
    {
      
        int n=s.length();
        if(n==1)
        return 0;
       vector<int>dp(n+1,-1);
        return solve(0,n-1,s,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends