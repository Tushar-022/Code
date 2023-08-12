//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{

 void calLps(string &pat, vector<int> &lps) {
        int i = 1;
        int len = 0;
        lps[0] = 0;
        while (i < pat.length())
        {
            if (pat[i] == pat[len]) 
            {
                len++;
                lps[i] = len;
                i++;
            } else
            {
                if (len != 0)
                 {
                    len = lps[len - 1];
                 } 
                else 
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return;
    }
    
    
    bool kmp(string str, string pat) {
        vector<int> lps(pat.length());
        calLps(pat, lps); // Call callps with pat instead of str
        int i = 0;
        int j = 0;
        while (i < str.length())
         {
            if (str[i] == pat[j]) 
            {
                i++;
                j++;
                if (j == pat.length())
                    return true;
            }
             else 
            {
               if(j!=0)
                j = lps[j - 1];
            else
                i++;
            }
        }
        return false;
    }
    
    public:
    int repeatedStringMatch(string pat, string str) 
    {
         int m = pat.size();
        int x = str.size();
        int n = x / m;
        int cnt = n;

        string ans = "";
        while (n--)
         {
            ans += pat;
        }

        if (kmp(ans, str)) {
            return cnt;
        }

        ans += pat;
        if (kmp(ans, str)) {
            return cnt + 1;
        }

        ans += pat;
        if (kmp(ans, str)) {
            return cnt + 2;
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution obj;
        cout<<obj.repeatedStringMatch(A,B)<<"\n";
    }
    return 0;
}

// } Driver Code Ends