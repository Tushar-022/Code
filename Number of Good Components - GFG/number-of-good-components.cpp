//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    void dfs(int i,int s,vector<vector<int>>&adj,vector<int>&vis,bool &flag,int &node)
    {
     vis[i]=1;
     node++;
     if(s!=adj[i].size())
     {
         flag=false;
     }
     for(auto it:adj[i])
     {
         if(!vis[it])
         dfs(it,s,adj,vis,flag,node);
     }
    }
    int findNumberOfGoodComponent(int v, vector<vector<int>>& adj) {
        
        int ans=0;
        vector<int>vis(v+1,0);
        
        for(int i=1;i<=v;i++)
        {
            if(!vis[i])
            {
                int node=0;
                bool flag=1;
               // cout<<adj[i].size()<<endl;
                
                dfs(i,adj[i].size(),adj,vis,flag,node);
                if(flag and node-1==adj[i].size())
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends