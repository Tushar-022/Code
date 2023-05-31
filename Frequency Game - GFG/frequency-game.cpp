//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    
    int LargButMinFreq(int nums[], int n) {
         map<int, int> mp;
        int ans = 0;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        int max1 = INT_MIN;
        int min1 = INT_MAX;
        for(auto & it: mp){
            max1 = max(max1, it.first); //max element
            min1 = min(min1, it.second); //min frequency
            
            if(it.first >= max1 && it.second <= min1){
                ans = it.first;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends