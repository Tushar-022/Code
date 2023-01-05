//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for
//User function Template for C++

class trie
{
    public:
    trie* links[26]={};
    bool end=false;
    
    bool insert(trie* root,string &s)
    {
        bool pre=true;
        for(int i=0;i<s.size();i++)
        {
            if(root->links[s[i]-97]==NULL)
            {
                root->links[s[i]-97]= new trie();
            }
            root=root->links[s[i]-97];
            if(i+1!=s.size() && root->end==false)
            {
                pre=false;
            }
        }
        root->end=true;
        return root->end && pre;
    }
};
class Solution
{
public:
    string longestString(vector<string> &words)
    {
        int len=0,size;
        trie root;
        string ans;
        sort(begin(words),end(words));
        for(auto &word: words)
        {
            size=word.size();
            if(root.insert(&root,word) && len<=size)
            {
                len==size?ans=min(ans,word):ans=word;
                len=size;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends