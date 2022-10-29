//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// class Solution{
// public:
//     vector<vector<string>> displayContacts(int n, string contact[], string s)
//     {
        
//     }
// };



class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        unordered_map<string,set<string>> mp;
        string st="";
        for(int i=0; i<n; i++){
            st = "";
            for(int j=0; j<contact[i].length(); j++){
                st = st+contact[i][j];
                mp[st].insert(contact[i]);
            }
        }
        vector<vector<string>> ans;
        st="";
        for(int i=0; i<s.length(); i++){
            st = st + s[i];
            if(mp.find(st)!=mp.end()){
                vector<string> vec;
                for( auto i : mp[st]){
                    vec.push_back(i);
                }
                ans.push_back(vec);
            }
            else{
                // vector<string> v;
                // v.push_back("0");
                ans.push_back({"0"});
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends