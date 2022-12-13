//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
        void findcombination(int index,vector<int> &arr,vector<vector<int>>&ans,vector<int>&t,int k)
        {
        
                if(k==0)
                {
                    ans.push_back(t);
                return;
                }
        
            for(int i=index;i<arr.size();i++)
            {
                if(i>index && arr[i]==arr[i-1])
                continue;
                if(arr[i]>k)
                break;
                t.push_back(arr[i]);
                findcombination(i+1,arr,ans,t,k-arr[i]);
                t.pop_back();
            }
        }
     
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        vector<int>t;
        findcombination(0,arr,ans,t,k);
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
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends