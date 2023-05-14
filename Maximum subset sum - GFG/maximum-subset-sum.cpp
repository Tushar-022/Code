//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
  
    long long solve(int ind,int n,vector<int> &nums,vector<long long>&dp)
    {
        if(ind<0)
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        //int npick=INT_MIN;
      return dp[ind]=max(nums[ind]+solve(ind-1,n,nums,dp),nums[ind-1]+solve(ind-2,n,nums,dp));
     // int pick=0;
      //if(nums[ind]>0)
       // pick=nums[ind]+solve(ind-1,n,nums,dp);
       // return dp[ind]=npick;
    }
    long long findMaxSubsetSum(int n, vector<int> &nums) {
        vector<long long>dp(n+1,-1);
        return solve(n-1,n,nums,dp);
    //   int sum=0;
    //   for(int i=0;i<n;i++)
    //   {
    //       if(nums[i]>0)
    //       sum+=nums[i];
    //   }
    //   return sum;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends