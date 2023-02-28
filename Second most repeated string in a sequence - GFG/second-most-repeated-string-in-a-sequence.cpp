//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    typedef pair<int,string>pi;
    
    string secFrequent (string arr[], int n)
    {
        
        map<string,int>m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        {
            for(auto it:m)
            {
                pq.push(make_pair(it.second,it.first));
                if(pq.size()>2)
                pq.pop();
            }
           
        }
        if(pq.size()>1)
            return pq.top().second;
            else
            return "";
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends