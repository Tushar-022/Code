//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        vector<int>ans;
        int xorpq=0;
        for(int i=0;i<nums.size();i++)
        {
            xorpq^=nums[i];
        }
        int t=xorpq &  -xorpq;
        int res1=0,res2=0;
        for(int i=0;i<nums.size();i++)
        {
            if((t & nums[i])!=0)
            res1^=nums[i];
            else
            res2^=nums[i];
        }
        ans.push_back(res1);
        ans.push_back(res2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends