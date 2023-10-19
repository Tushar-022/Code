//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int v, vector<int> adj[], int x) 
	{
	    queue<int>q;
	    int lvl=0;
	    vector<int>vis(v,0);
	    if(x==0)
	    return 0;
	    
	    q.push(0);
	    vis[0]=1;
	    while(!q.empty())
	    {
	        int size=q.size();
	        lvl++;
	        for(int i=0;i<size;i++)
	        {
	            int node=q.front();
	            q.pop();
	        
    	        for(auto it:adj[node])
    	        {
    	            if(!vis[it])
    	            {
    	                if(it==x)
    	                return lvl;
    	                q.push(it);
    	                vis[it]=1;
    	                
    	            }
    	        }
	        }
	        
	        
	    }
	    if(vis[x]==0)
	    return -1;
	    return lvl;
	    
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends