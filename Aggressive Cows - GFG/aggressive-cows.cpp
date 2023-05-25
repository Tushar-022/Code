//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    
    bool isvalid(int mid,int k,vector<int>&stalls,int n)
    {
        int dis=stalls[0], cow=1;
        for(int i=1;i<n;i++)
        {
            
            if(stalls[i]-dis>mid)
            {
                dis=stalls[i];
                cow++;
                if(cow==k)
                return true;
            }
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
    sort(stalls.begin(),stalls.end());
    int low=1;
    int high=stalls[n-1]-stalls[0];
    while(high>=low)
    {
        int mid=low+(high-low)/2;
        if(isvalid(mid,k,stalls,n))
        {
            low=mid+1;
        }
        else
        high=mid-1;
        
    }
    return low;
    return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends