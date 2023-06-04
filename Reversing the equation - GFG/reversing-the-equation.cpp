//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string reverseEqn(string s)
    {
        stack<string> st;
        int n = s.length();
        string p = "";
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                st.push(p);
                st.push(string(1, ch)); // Convert character to string and push onto stack
                p = "";
            }
            else
                p += ch;
        }
        st.push(p);
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends