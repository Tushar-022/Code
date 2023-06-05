//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
void dfs(int i, stack<int>& st, vector<int>& vis, vector<vector<int>>& adj) {
    vis[i] = 1;
    for (auto it : adj[i]) {
        if (!vis[it])
            dfs(it, st, vis, adj);
    }
    st.push(i);
}

void dfs2(int i, vector<int>& vis, vector<vector<int>>& adjT) {
    vis[i] = 1;
    for (auto it : adjT[i]) {
        if (!vis[it])
            dfs2(it, vis, adjT);
    }
}

int kosaraju(int v, vector<vector<int>>& adj) {
    vector<int> vis(v, 0);
    stack<int> st;
    for (int i = 0; i < v; i++) {
        if (!vis[i])
            dfs(i, st, vis, adj);
    }
    vector<vector<int>> adjT(v);

    for (int i = 0; i < v; i++) {
        vis[i] = 0;
        for (auto it : adj[i]) {
            adjT[it].push_back(i);
        }
    }

    int scc = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            scc++;
            dfs2(node, vis, adjT);
        }
    }
    return scc;
}

};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends