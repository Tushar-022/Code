//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

//class Solution{
// public:
//     int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)
//     {
        
//     }
//};
// User function Template for C++

class Solution{

    private :

    int fun(int n,int m,vector<vector<int>> grid,int delrow[],int delcol[],int i,int j,int size)

    {

        int ans = 0;

        for(int k = 0;k<size;k++)

        {

            int nrow = delrow[k] + i;

            int ncol = delcol[k] + j;

            if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m){

                ans = ans + grid[nrow][ncol];

            }

        }

        return ans;

    }

public:

    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)

    {

       // for 1 step

        int dx1o[] = {-1,0,1,1,1,0};

        int dy1o[] = {0,1,1,0,-1,-1};

        int dx1e[] = {-1,-1,0,1,0,-1};

        int dy1e[] = {0,1,1,0,-1,-1};

        //for 2step

        int dx2o[] = {-1,-1,-2,-1,-1,0,0,1,1,2,2,2};

        int dy2o[] = {-2,-1,0,1,2,-2,2,-2,2,-1,0,1};

         int dx2e[] = {-2,-2,-2,-1,-1,0,0,1,1,1,1,2};

        int dy2e[] = {-1,0,1,-2,2,-2,2,-2,-1,1,2,0};

        // 1step

        int ans = 0;

        if(ty == 0)

        {

            if(j%2 == 0)

            {

                ans = fun(n,m,mat,dx1e,dy1e,i,j,6);

            }

            else

            {

                ans = fun(n,m,mat,dx1o,dy1o,i,j,6);

            }

        }

        else

        {

            //2step

            if(j%2 == 0)

            {

                ans = fun(n,m,mat,dx2e,dy2e,i,j,12);

            }

            else

            {

                ans = fun(n,m,mat,dx2o,dy2o,i,j,12);

            }

        }

        

        return ans;

    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>ty>>i>>j;
        
        Solution ob;
        cout<<ob.hopscotch(n, m, mat, ty, i, j)<<"\n";
    }
    return 0;
}
// } Driver Code Ends