//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  
   int subsetsum(vector<int>& A,int sum)
    {
        int i,j;
         int n=A.size();
        int t[n+1][sum+1];
            for( i=0;i<n+1;i++)
            {
                for( j=0;j<sum+1;j++)
                {
                    if(i==0)
                    t[i][j]=0;
                    if(j==0)
                    t[i][j]=1;
                    //t[0][0]=1;
                }
            }
            for( i=1;i<n+1;i++)
            {
                for( j=0;j<sum+1;j++)
                {
                   if(A[i-1]<=j)
                    t[i][j]=t[i-1][j-A[i-1]]+t[i-1][j];
                else
                    t[i][j]=t[i-1][j]; 
                }
            }
        
        return t[n][sum];
            
        } 
    int findTargetSumWays(vector<int>&A ,int target) {
    
        int n=A.size();
        int sum=0;
        for(int i=0;i<n;i++)
        sum+=A[i];
        if((sum+target)%2!=0)
         return 0;
        int s=(sum+target)/2;
        return subsetsum(A,s);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends