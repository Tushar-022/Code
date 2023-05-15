//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int power(long long  n){
        long long c=0;
        while((1<<c)<=n){
            c++;
        }
        return c-1;
    }
    long long countBits(long long n) {
     
        //x=nearestpow
        if(n==0)
        return 0;
       long long x=power(n);
       long long b2x=(1<<x-1)*x;
        long long msbfrom2xton=(n-(1<<x)+1);
       long long rest=n-(1<<x);
       long long ans=b2x+msbfrom2xton+countBits(rest);//recursively call for rest
       return ans;
    }
};
        // code here


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends