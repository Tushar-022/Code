//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
    vector<string> CamelCase(int n, vector<string> dict, string pat) {
        vector<string> v;
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int j = 0; j < dict[i].length(); j++) {
                if (dict[i][j] >= 'A' && dict[i][j] <= 'Z') {
                    s += dict[i][j];
                }
                if (s == pat) {
                    v.push_back(dict[i]);
                    break;
                }
            }
        }

        if (v.empty()) {
            v.push_back("-1");
        }

        return v;
    }
};







//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends