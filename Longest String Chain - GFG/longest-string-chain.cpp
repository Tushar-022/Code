//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  
  
  static bool comp(string &s1,string &s2)
    {
        return s1.size()<s2.size();
    }
        
    
        bool checkpossible(string &s1,string &s2)
        {
            if(s1.size()!=s2.size()+1)
                return false;
          int first=0,second=0;
            while(first<s1.size())
            {
                if(s1.size()>second&& s1[first]==s2[second])
                { first++;
                second++;
                }
                else
                first++;
            }
            
            
            if(first==s1.size() && second==s2.size())
                return true;
            return false;
        }
    //int longestStrChain(vector<string>& words) {
       
  
  
    int longestChain(int n, vector<string>& words) {
        
         sort(words.begin(),words.end(),comp);
        int maxi=1;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(checkpossible(words[i],words[prev])&& 1+dp[prev]>dp[i])
                    dp[i]=dp[prev]+1;
                
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i]>maxi)
                maxi=max(dp[i],maxi);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends