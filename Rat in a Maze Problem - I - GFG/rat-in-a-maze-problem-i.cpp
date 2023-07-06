//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


 int delrow[] = {1,0,0,-1};
 int delcol[] = {0,-1,1,0};

class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& m, int n, vector<vector<int>>& vis, string move, vector<string>& ans) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }
        string dirs = "DLRU";

        for (int ind = 0; ind < 4; ind++) {
            int nrmove = i + delrow[ind];
            int ncmove = j + delcol[ind];

            if (nrmove >= 0 && nrmove < n && ncmove >= 0 && ncmove < n && !vis[nrmove][ncmove] && m[nrmove][ncmove] == 1) {
                vis[i][j] = 1;
                solve(nrmove, ncmove, m, n, vis, move + dirs[ind], ans);
                vis[i][j] = 0;
            }
        }
    }

    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> ans;
        if (m[0][0] == 0)
            return ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        solve(0, 0, m, n, vis, "", ans);
        return ans;
    }
};



    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends