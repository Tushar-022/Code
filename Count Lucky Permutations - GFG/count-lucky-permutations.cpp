//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int luckyPermutations(int N, int m, vector<int> arr,
                                    vector<vector<int>> graph) {
        vector<vector<int>> adj(N,vector<int>(N,0));
        for(auto x:graph){
            adj[x[0]-1][x[1]-1]=1;
            adj[x[1]-1][x[0]-1]=1;
        }
        vector<vector<long long int>> dp(N,vector<long long int>(pow(2,N),0));
        for(int i=0;i<N;i++){
            dp[i][pow(2,i)]=1;
        }
        int p = pow(2,N);
        for(int bit =1 ;bit<p;bit++){
            for(int i=0;i<N;i++){
                if(1&(bit>>i))
                for(int j=0;j<N;j++){
                    if((1&(bit>>j)) and arr[i]!=arr[j] and adj[arr[i]-1][arr[j]-1]){
                        dp[i][bit]+=dp[j][bit^(1<<i)];
                    }
                }
            }
        }
        long long int ans=0;
        for(int i=0;i<N;i++){
            ans+=dp[i][p-1];
        }
        return ans; }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<int> arr(N);
        vector<vector<int>> graph(M, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> graph[i][j];
            }
        }
        Solution obj;
        cout << obj.luckyPermutations(N, M, arr, graph) << endl;
    }
}

// } Driver Code Ends