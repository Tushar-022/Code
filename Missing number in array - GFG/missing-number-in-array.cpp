//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int MissingNumber(vector<int>& arr, int n) {
      vector<int>v(n+1,0);
      v[0]=1;
      for(int i=0;i<n-1;i++)
      {
          v[arr[i]]=1;
      }
    //   for(auto it:v)
    //   cout<<it<<" ";
     // cout<<endl;
      for(int i=1;i<=n;i++)
      {
          if(v[i]==0)
          return i;
      }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends