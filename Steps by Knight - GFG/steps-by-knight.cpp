//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&knightpos,vector<int>&targetpos,int n)
	{
	    int srow=knightpos[0];
	    int scol=knightpos[1];
	    
	    int erow=targetpos[0];
	    int ecol=targetpos[1];
	    vector<vector<int>>vis(n+1,vector<int>(n+1,0));
	    vis[srow][scol]=1;
	   // int sum1=srow+scol;
	   // int sum2=erow+ecol;
	   // if(sum1%2==0 && sum2%2==0 || sum1%2==1 && sum2%2==1)
	   // return -1;
	    
	     int delrow[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
         int delcol[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
 
	    queue<pair<pair<int,int>,int>>q;
	    int moves=0;
	    q.push({{srow,scol},0});
	    while(!q.empty())
	    {
	        auto node=q.front();
	        int row=node.first.first;
	        int col=node.first.second;
	         moves=node.second;
	         //cout<<row<<" "<<col<<endl;
	         if(row==erow && col==ecol)
	         return moves;
	         q.pop();
	        for(int i=0;i<8;i++)
	        {
	            int nrow=row+delrow[i];
	            int ncol=col+delcol[i];
	        
    	        if(nrow>=0 && nrow<=n && ncol>=0 && ncol<=n && !vis[nrow][ncol])
    	        {
    	            vis[nrow][ncol]=1;
    	            q.push({{nrow,ncol},moves+1});
    	        }
	        }
	        
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends