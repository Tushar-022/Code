//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int getAngle(int H , int M) {
       double hrAngle=H*30+((double)M/2);
       // cout<<hrAngle<<" ";
        int minAngle=M*6;
        
        return min(floor(abs(hrAngle-minAngle)),floor(360-abs(hrAngle-minAngle)));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int H,M;
        
        cin>>H>>M;

        Solution ob;
        cout << ob.getAngle(H,M) << endl;
    }
    return 0;
}
// } Driver Code Ends