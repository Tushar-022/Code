//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// class Solution {
//   public:
//     long long countPairs(int n, int arr[], int k) {

//         // code here
//      unordered_map<int, int> map;
//         long long ans = 0;
        
//         for(int i=0; i<n; i++){
            
//             ans += map[arr[i]%k];
//             map[arr[i]%k]++;
//         }
        
//         return ans;
        
//     }
// };

//User function Template for C++

class Solution {
  public:
    // Function to count the number of pairs in the given array
    // that have a difference divisible by k
    long long countPairs(int n, int arr[], int k) {
        long long ans = 0; // variable to store the number of pairs

        // unordered_map to store the number of occurrences of each remainder
        unordered_map<int,int> mp;
        
        // Iterate through the array
        for (int i = 0; i < n; i++) {
            int r = arr[i] % k; // get the remainder of the current element when divided by k
            // If there are any elements that have the same remainder,
            // these elements can be paired with the current element
            // to form a difference divisible by k
            if (mp.find(r) != mp.end()) {
                ans += mp[r];
            }
            // Increment the number of occurrences of the current remainder
            mp[r]++;
        }

        return ans;
    }
};
        

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}
// } Driver Code Ends