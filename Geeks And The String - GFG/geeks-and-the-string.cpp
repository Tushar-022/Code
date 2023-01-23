//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(st.empty())
         {
            st.push(s[i]);
         }
         else if(st.top()==s[i])
         {
             st.pop();
         }
         else
         {
             st.push(s[i]);
         }
        }
        string ans;
        string str;
        if(st.size()==0)
        {
            str+="-1";
            return str;
        }
        while(st.size()!=0)
        {
            ans+=st.top();
            st.pop();
        }
        reverse (ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends