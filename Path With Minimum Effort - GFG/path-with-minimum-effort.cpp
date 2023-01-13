//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int,pair<int,int>>pii;
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        
        
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>distance(m,vector<int>(n,1e9));
        distance[0][0]=0;
        int mineff=0;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,{0,0}});
        int delr[]={-1,1,0,0};
        int delc[]={0,0,1,-1};
        while(!pq.empty())
        {
            auto t=pq.top();
            pq.pop();
            int diff=t.first;
            int row=t.second.first;
            int col=t.second.second;
            if(row==m-1 && col==n-1)
            return diff;
            for(int i=0;i<4;i++)
            {
                int nrow=row+delr[i];
                int ncol=col+delc[i];
                if(nrow>=0 &&  nrow<m &&ncol>=0 && ncol<n)
                {
                    int neweffort=max(abs(heights[nrow][ncol]-heights[row][col]),diff);
                    if(neweffort<distance[nrow][ncol])
                    {
                        distance[nrow][ncol]=neweffort;
                        pq.push({neweffort,{nrow,ncol}});
                    }
                    
                }
            }
            
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends