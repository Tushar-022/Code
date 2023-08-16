//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int kadane(vector<int>&v)
    {
        int csum=v[0];
        int osum=v[0];
        for(int i=1;i<v.size();i++)
        {
            if(csum>=0)
            {
                csum+=v[i];
            }
            else
            csum=v[i];
            osum=max(csum,osum);
        }
        return osum;
    }
    int maximumSumRectangle(int r, int c, vector<vector<int>>mat) {
        int ans=INT_MIN;
        for(int i=0;i<r;i++)
        {
            vector<int>v(c,0);
            for(int row=i;row<r;row++)
            {
                for(int col=0;col<c;col++)
                {
                    v[col]+=mat[row][col];
                }
                int curr=kadane(v);
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};


// User function Template for C++

// class Solution {
//   public:
   
//     int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
//         // code here
//         int mx=-9999;
//         for(int i=0;i<C;i++){
//          vector<int>v(R,0);
//             for(int j=i;j<C;j++){
//                 for(int row=0;row<R;row++){
//                     v[row]+=M[row][j];
//                 }
//                 int curr=kadane(v);
//                   mx = max(mx,curr);
//             }
//         }
//         return mx;
//     }
// };



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends