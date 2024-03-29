//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int mod=1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        if(start==end)
        return 0;
        queue<pair<int,int>> q;
       q.push({0,start});
              
       vector<int> vis(1e5 , 0);
       vis[start] = 1;
       
       while(!q.empty())
       {
           auto p = q.front();
           q.pop();
           int steps = p.first;
           int node = p.second;
           
           for(auto it:arr)
            {

                int temp = (it*node)%mod;

                    if(!vis[temp])
                    {
                        vis[temp]=1;
                    if(temp == end)return steps+1;
                    q.push({steps+1,temp});
                  
                     }
            
            }
             
         }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends