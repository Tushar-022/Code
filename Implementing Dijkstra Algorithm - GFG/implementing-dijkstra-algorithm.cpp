//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
	public:
	
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    typedef pair<int,int>pi;
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int src)
    {
        vector<int>dis(v,1e9);
        queue<pair<int,int>>q;
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        pq.push({src,0});
        dis[src]=0;
        while(!pq.empty())
        {
            int node=pq.top().first;
            int dist=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int adjnode=it[0];
                int edgewt=it[1];
                if(dist+edgewt<dis[adjnode])
                {
                    dis[adjnode]=dist+edgewt;
                    pq.push({adjnode,dist+edgewt});
                }
            }
        }
        return dis;
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends