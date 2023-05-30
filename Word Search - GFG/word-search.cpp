//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:

    bool dfs(vector<vector<char>>& board,int row,int col,int len,string &word,vector<vector<int>>&vis)
    {
        int m=board.size();
        int n=board[0].size();
        vis[row][col]=1;
        if(len>=word.size())
            return true;
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && board[nrow][ncol]==word[len])
            {
               // vis[nrow][ncol]=1;
                if (dfs(board, nrow, ncol, len + 1, word, vis))
                return true;
            
            }
           
        }
       vis[row][col] = 0;
       return 0;

    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0] && !vis[i][j])
                {
                   
                    if(dfs(board,i,j,1,word,vis))
                    return true;
                }
                
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends