//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int r, int c){
        //0 for right
        //1 for down
        //2 for left
        //3 for up
        int i=0,j=0;
        int chal=0;
        pair<int,int>ans;
        while(i>=0 && j>=0 && i<r && j<c)
     {
        ans.first=i;
        ans.second=j;
        if(matrix[i][j])
     {
        matrix[i][j]=0;
    if(chal==0)
    {
        chal=1;
        i++;
    }
    else if(chal==1)
    {
        chal=2;
        j--;
    }
    else if(chal==2)
    {
        chal=3;
        i--;
    }
    else
    {
        chal=0;
        j++;
    }
        }
        else
        {
            if(chal==0)
            j++;
            else if(chal==1)
            i++;
            else if(chal==2)
            j--;
            else
            i--;
        }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends