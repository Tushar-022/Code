//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        
        
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        {
            for(int i=0;i<n;i++)
            {
                 if(arr[i]!=x)
                {
                    pq.push({-1*abs(arr[i]-x),arr[i]});
                }
                //if(pq.size()>k)
                // pq.pop();
            }
        }
        
        // while(k>0)
        // {
        //     if(x==pq.top().second)
        //     pq.pop();
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        //     k--;
            
        // }
        
        for(int i=0;i<k;i++)
        {
           
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends