//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C
//User function Template for C++
class Solution
{
    long long int hs,cnt,lower,local;
    void dfs(int i,vector<int> &edge,int n,vector<int> &vis,vector<int> &store){
        vis[i]=cnt;
        store[i]=local;
        local+=i;
        cnt++;
        if(edge[i]==-1)return;
        if(vis[edge[i]]==0)dfs(edge[i],edge,n,vis,store);
        else{
            if(vis[edge[i]]<lower)return;
            hs=max(hs,local-store[edge[i]]);
        }
    }
  public:
  long long largestSumCycle(int N, vector<int> Edge)
  {
    // code here
    hs=-1,cnt=1;
    vector<int> vis(N),store(N);
    for(int i=0;i<N;i++){
        if(vis[i]==0){
            local=0;
            lower=cnt;
            dfs(i,Edge,N,vis,store);
        }
    }
    return hs;
    
  }
};


//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends