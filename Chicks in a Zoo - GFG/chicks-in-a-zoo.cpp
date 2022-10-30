//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//     #define ll long long int;
class Solution {
// public:

    
        
// 	long long int NoOfChicks(int n){
// 	    int size = max(n, 7);
// 	    ll dp[size];
 
//     dp[0] = 0;
//     dp[1] = 1;
 
//     // Every day current population
//     // will be three times of the previous day
//     for (int i = 2; i <= 6; i++) {
//         dp[i] = dp[i - 1] * 3;
//     }
 
//     dp[7] = 726;

        public:
	long long int NoOfChicks(int n){
	    // Code here
	    vector<long long> arr(n+1,0);
	    long long curr=1;
	    arr[0]=0;
	    arr[1]=1;
	    for(int i=2;i<=n;i++)
	    {
	        if(i-6>=0)
	            curr-=arr[i-6];
	        arr[i]=curr*2;
	        curr+=arr[i];
	    }
	    return curr;
	}
};


 

//     for (int i = 8; i <= n; i++) {
 
   
//         dp[i] = (dp[i - 1] - (2 * dp[i - 6] / 3)) * 3;
//     }
 
//     return dp[n];
// }
 
// Driver code
// int int n = 3;
 
//     cout << getChicks(n);
 
//     return 0;
	   
// 	} main()
// {
   
// };

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends