//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    
	    vector<int>adj[n];
	    for(auto it:prerequisites)
	    adj[it.first].push_back(it.second);
	    
	    vector<int>topo;
	    vector<int>vis(n,0);
	    queue<int>q;
	    vector<int>indegree(n,0);
	    for(int i=0;i<n;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	        
	    }
	    
	    while(!q.empty())
	    {
	        
	        int node=q.front();
	        topo.push_back(node);
	        q.pop();
	        for(auto it:adj[node])
	        {
	                indegree[it]--;
	                if(indegree[it]==0)
	                q.push(it);
	        }
	    }
	    if(topo.size()==n)
	    return true;
	    else
	    return false;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends