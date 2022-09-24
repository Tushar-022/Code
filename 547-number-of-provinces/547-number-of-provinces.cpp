class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int V=isConnected.size();
                vector<int>adjLs[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int>vis(V,0);
        int cnt=0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                queue<int>q;
                q.push(i);
                cnt++;
                //vis[i]=1;
            
            while(!q.empty())
             {
                int node=q.front();
                q.pop();
                for(auto it: adjLs[node])
                {
                    if(!vis[it])
                    {
                        q.push(it);
                        vis[it]=1;
                    }
                }
             }
            } 
        }
        return cnt;
        
    }
};