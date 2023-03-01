//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    typedef long long ll;
    long long minCost(long long arr[], long long n) {
        
        ll ans=0;
        if(n==1)
        return 0;
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        while(pq.size()>2)
        {
            ll x=pq.top();
            pq.pop();
            ll y=pq.top();
            pq.pop();
            pq.push(x+y);
            ans+=x+y;
        }
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends