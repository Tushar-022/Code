//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string s, string t) {
       int i=0,j=0;
       while(i<t.length() && j<s.length())
       {
           int cnt=0;
           while(i < s.size() and j < t.size()){
            if(s[i] == t[j])
           {
               i++;
               j++;
           }
            else if(isdigit(t[j])){
            int num = 0;
            while(j < t.size() and isdigit(t[j])){
            num *= 10;
            num += (t[j++]-'0');
            }
            i += num;
            }
            else 
            return 0;
        }
        return i == s.size() and j == t.size();
       }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends