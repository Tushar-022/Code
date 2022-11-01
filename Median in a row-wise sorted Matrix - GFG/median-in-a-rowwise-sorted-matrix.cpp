//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// class Solution{   
// public:
//     int median(vector<vector<int>> &matrix, int R, int C){
//         // code here          
//     }
// };

        
class Solution{   
public:
int check(vector<vector<int>>&matrix,int n){
    int count=0;
    for(int i=0;i<matrix.size();i++){
        int j=0;;
        while(j<matrix[0].size() && matrix[i][j]<=n){
            count++;
            j++;
        }
    }
    return count;
}
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here          
        int s=INT_MAX;
        int e=INT_MIN;
        int n=((R*C)/2)+1;
        for(int i=0;i<R;i++){
            s=min(s,matrix[i][0]);
            e=max(e,matrix[i][C-1]);
        }
        int ans=0;
       while(s<=e){
           int m=s+(e-s)/2;
           int res=check(matrix,m);
           
           if(res<n){
               s=m+1;
           }
          
           else{
               e=m-1;
           }
       }
       return s;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends