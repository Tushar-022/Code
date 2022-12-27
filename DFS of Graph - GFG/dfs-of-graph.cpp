//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Funct
    void dfs1(int node,vector<int> &dfs,vector<int> &vis,vector<int>adj[])
    {
        vis[node]=1;
        dfs.push_back(node);
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs1(it,dfs,vis,adj);
            }
        }
    }
  
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int>dfs;
        vector<int>vis(V,0);
        int start=0;
         dfs1(start,dfs,vis,adj);
         return dfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends