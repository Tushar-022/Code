//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int,int> pii;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        vector<int>distance(v,1e9);
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        
        distance[s]=0;
        pq.push({s,0});// source and distance
        
        while(!pq.empty())
        {
            int node=pq.top().first;
            int dis=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                
                int adjnode=it[0];
                int edgeweight=it[1];
                if(dis+edgeweight<distance[adjnode])
                {
                    distance[adjnode]=dis+edgeweight;
                    pq.push({adjnode,distance[adjnode]});
                }
            }
        }
        
        return distance;
        
        
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