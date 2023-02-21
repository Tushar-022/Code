//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int n, int m, int x, int y){    
       queue<pair<pair<int,int>,int>>q;
      vector<vector<int>>vis(n,vector<int>(m,0));
       q.push({{x-1,y-1},0});
       vis[x-1][y-1]=1;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
       int t=0;
       
        while(!q.empty())
        {
            auto it=q.front();
            int row=it.first.first;
            int col=it.first.second;
             t=it.second;
            
           // cout<<row<<" "<<col<<endl;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
            
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && vis[nrow][ncol]==0)
            {
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol},t+1});
                
            }
            
            }
            
        }
        return t;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends