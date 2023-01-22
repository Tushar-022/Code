//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
 
	public:
	int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>> &mat)
	{
		// Your code goes here
		
		if(mat[r][c]=='#')
		return 0;
		
		queue<pair<pair<int,int>,pair<int,int>>>q;
		q.push({{r,c},{u,d}});
		int ans=1;
		vector<vector<int>>vis(n,vector<int>(m,0));
		vis[r][c]=1;
		
		while(!q.empty())
		{
		    auto it=q.front();
		    int row=it.first.first;
		    int col=it.first.second;
		    int up=it.second.first;
		    int down=it.second.second;
		    q.pop();
		    if(col-1>=0 && mat[row][col-1]=='.' && !vis[row][col-1])
		    {
		        q.push({{row,col-1},{up,down}});
		        vis[row][col-1]=1;
		        ans++;
		    }
		    
		    if(col+1<m && mat[row][col+1]=='.' && !vis[row][col+1])
		    {
		        q.push({{row,col+1},{up,down}});
		        vis[row][col+1]=1;
		        ans++;
		    }
		    
		    if(row-1>=0 && up>0 && mat[row-1][col]=='.' && !vis[row-1][col])
		    {
		        q.push({{row-1,col},{up-1,down}});
		        vis[row-1][col]=1;
		        ans++;
		    }
		    
		    if(row+1<n && down>0 && mat[row+1][col]=='.' && !vis[row+1][col])
		    {
		        q.push({{row+1,col},{up,down-1}});
		        vis[row+1][col]=1;
		        ans++;
		    }
		    
		    
		}
		return ans;
		
	}

};


//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;

    while (t--)
    {
    	int n, m, r, c, u, d;
        cin >> n >> m >> r >> c >> u >> d;
        
        vector<vector<char>> mat(n, vector<char>(m, '.'));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{
        		cin >> mat[i][j];
        	}
        }

      

        Solution obj;
        cout << obj.numberOfCells(n, m, r, c, u, d, mat) << "\n";
    
    }

    return 0;
}



// } Driver Code Ends