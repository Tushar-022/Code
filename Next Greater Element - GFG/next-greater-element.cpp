//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution
  using ll=long long;
class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr,int n){
        
        
        vector<ll>ans;
        stack<ll>s;
        for(ll i=(long long)n-1;i>=0;i--)
        {
            if(s.size()==0)
            ans.push_back(-1);
            else if( s.top()>arr[i])
            ans.push_back(s.top());
            else
            {
                while(s.size()>0 && s.top()<arr[i])
                s.pop();
                if(s.size()==0)
                ans.push_back(-1);
                else
                ans.push_back(s.top());
            }
            s.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends