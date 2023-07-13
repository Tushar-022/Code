//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
         stack<int>index;// storing the index when encountering opening brackets
        int ans=0;
        index.push(-1);// taaki len 2 aa jaae jb indexes subtract kare
        int n=s.length();

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            index.push(i);
            else
            {
              index.pop();
              if(index.size()==0)
              index.push(i);
              else
              ans=max(ans,i-index.top());
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
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends