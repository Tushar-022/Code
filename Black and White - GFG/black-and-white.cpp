//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
// long long numOfWays(int N, int M)
// {
//     // write code here
// }


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int N, int M)
{
    long long total=0;
    long long mod = 1000000007;
    
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            
            long long curr=N*M;
            int invalid=1;
            
            int dr[]={-1 , +1 , +2, +2, -1, +1, -2, -2};
            int dc[]={+2 , +2 , -1, -1, -2, -2, -1, +1};
            
            for(int r=0; r<8; r++){
                
                int nr=i+dr[r];
                int nc=j+dc[r];
                
                if(nr>=0 and nr<N and nc>=0 and nc<M){
                    invalid++;
                }
            }
            
            curr -= invalid;
            total = (total%mod+curr%mod)%mod;
        }
    }
    return total;
}