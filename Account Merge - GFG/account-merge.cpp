//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class DisjointSet{
    public:
    vector<int>rank,par;
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        par.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            par[i]=i;
        }
    }
    int findPar(int node)
    {
        if(par[node]==node)
        return node;
        return par[node]=findPar(par[node]);
    }
    void UnionbyRank(int u,int v)
    {
        int p1=findPar(u);
        int p2=findPar(v);
        if(p1==p2)
        return;
        if(rank[p1]>rank[p2])
        par[p2]=p1;
        else if(rank[p2]>rank[p1])
        par[p1]=p2;
        else
        {
            rank[p1]++;
            par[p2]=p1;
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> m;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (m.find(mail) == m.end()) {
                    m[mail] = i;
                } else {
                    ds.UnionbyRank(i, m[mail]);
                }
            }
        }

        vector<string> mergeMail[n];
for (auto it : m) {
    string mail = it.first;
    int node = ds.findPar(it.second);
    mergeMail[node].push_back(mail);
}


        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergeMail[i].size() == 0)
                continue;
            sort(mergeMail[i].begin(), mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergeMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
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
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends