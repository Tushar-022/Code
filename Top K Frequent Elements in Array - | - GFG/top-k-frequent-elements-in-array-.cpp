//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  typedef pair<int,int>pi;
    struct comp{
        bool operator()(pi &a,pi &b){
            if(a.first==b.first)
            return a.second>b.second;
            else
            return a.first>b.first;
        }
    };
    vector<int> topK(vector<int>& nums, int k) {
        
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        m[nums[i]]++;
        
         priority_queue<pi,vector<pi>,comp>pq;
            for(auto it:m)
            {
                pq.push({it.second,it.first});
                if(pq.size()>k)
                pq.pop();
            }  
              while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        } 
        reverse(ans.begin(), ans.end());
        return ans;  
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends