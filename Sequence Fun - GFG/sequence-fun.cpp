//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
	
		int NthTerm(int n){
		    int i=0;
		    long mod=1e9+7;
		    long ele=2;
		    if(n==1)
		    {
		        return 2;
		    }
		    
		    else
		    {
		        for(int i=2;i<=n;i++)
		        {
		            ele=(ele*i+1)%mod;
		        
		        }
		        return ele%mod;
		    }
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends