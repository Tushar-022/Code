//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

   class DisjointSet{
    public:
    vector<int>rank,par;
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        par.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            par[i]=i;
        }
    }
    int findPar(int node)
    {
        if(par[node]==node)
        return node;
        return par[node]=findPar(par[node]);
    }
    void UnionbyRank(int u,int v)
    {
        int p1=findPar(u);
        int p2=findPar(v);
        if(p1==p2)
        return;
        if(rank[p1]>rank[p2])
        par[p2]=p1;
        else if(rank[p2]>rank[p1])
        par[p1]=p2;
        else
        {
            rank[p1]++;
            par[p2]=p1;
        }
        
    }
};
class Solution {
  public:
    int minimumConnections(vector<vector<int>>& edges,int n) {
        DisjointSet ds(n);
        int cntextras=0;
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findPar(u)==ds.findPar(v))
            cntextras++;
            else
            ds.UnionbyRank(u,v);
        }
        int comp=0;
        for(int i=0;i<n;i++)
        {
            if(ds.par[i]==i)
            comp++;
        }
        int ans=comp-1;
        if(cntextras>=ans)
        return ans;
        
        return -1;
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> c(m,vector<int> (2));
        for(auto &j:c)
            cin>>j[0]>>j[1];
        Solution s;
        cout<<s.minimumConnections(c,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends