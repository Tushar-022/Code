//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
         void dfs(int curr,int n,int m,int &ans){
        if(curr>m) return;
        if(curr>=n && curr<=m) ans++;
        int r = curr%10;
        if(r==9){
            dfs(curr*10+8,n,m,ans);
        }
        else if(r==0){
            dfs(curr*10+1,n,m,ans);
        }
        else{
            dfs(curr*10+(r+1),n,m,ans);
            dfs(curr*10+(r-1),n,m,ans);
        }
    }
    int steppingNumbers(int n, int m)
    {
        int ans=0;
        if(n==0) ans++;
        for(int i=1; i<=9; i++){
            dfs(i,n,m,ans);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends