//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int arr[], int n) {
        
        vector<int>temp;
        temp.push_back(arr[0]);
        for(int i=1;i<n;i++)
        {
            if(arr[i]>temp.back())
            temp.push_back(arr[i]);
            else
            {
                auto it=lower_bound(temp.begin(),temp.end(),arr[i]);
                *it=arr[i];
            }
        }
        return n-temp.size();
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends