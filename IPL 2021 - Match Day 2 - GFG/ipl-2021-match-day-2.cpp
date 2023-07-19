//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        
    vector<int> ans;
    deque<int> dq;
    
    int windowSize = 0;

    for (int j = 0; j < n; j++) {
        while (!dq.empty() && arr[j] > dq.back()) {
            dq.pop_back();
        }

        dq.push_back(arr[j]);
        windowSize++;

        if (windowSize == k) {
            ans.push_back(dq.front());

            if (dq.front() == arr[j - k + 1]) {
                dq.pop_front();
            }

            windowSize--;
        }
    }

    return ans;
}

};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends