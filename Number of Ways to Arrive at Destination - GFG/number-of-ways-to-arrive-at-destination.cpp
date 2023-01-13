//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
 typedef pair<int,int>pii;
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        int mod=int(1e9+7);
        vector<int>ways(n,0);
        vector<int>distance(n,1e9);
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        vector<pair<int,int>>adj[n];
        
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
            
        }
        distance[0]=0;
        ways[0]=1;
        pq.push({0,0}); //node,distance
        while(!pq.empty())
        {
            int node=pq.top().first;
            int dis=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int edgewt=it.second;
                
                if(edgewt+dis<distance[adjnode])
                {
                    distance[adjnode]=edgewt+dis;
                    pq.push({adjnode,distance[adjnode]});
                    ways[adjnode]=ways[node];
                }
                else if(edgewt+dis==distance[adjnode])
                {
                    ways[adjnode]+=(ways[node])%mod;
                }
            }
        }
       return ways[n-1]%mod; 
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends