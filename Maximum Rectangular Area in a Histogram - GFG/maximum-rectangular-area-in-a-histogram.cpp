//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<pair<long long,long long>>nsl;
        vector<long long>v1;
      for(int i=0;i<n;i++)
          {
              if(nsl.empty())
          v1.push_back(-1);
          else if(nsl.size()>0 && nsl.top().first<arr[i])
          v1.push_back(nsl.top().second);
          else if(nsl.size()>0 && nsl.top().first>=arr[i])
          {
              while(nsl.size()>0 && nsl.top().first>=arr[i])
              {
                  nsl.pop();
              }
              if(nsl.size()>0 && nsl.top().first<arr[i])
              v1.push_back(nsl.top().second);
              else
              v1.push_back(-1);
               
          }
          nsl.push({arr[i],i});
           
          }
          stack<pair<long long,long long>>nsr;
          vector<long long>v2;
      for(int i=n-1;i>=0;i--)
          {
              if(nsr.empty())
          v2.push_back(n);
          else if(nsr.size()>0 && nsr.top().first<arr[i])
          v2.push_back(nsr.top().second);
          else if(nsr.size()>0 && nsr.top().first>=arr[i])
          {
              while(nsr.size()>0 && nsr.top().first>=arr[i])
              {
                  nsr.pop();
              }
              if(nsr.size()>0 && nsr.top().first<arr[i])
              v2.push_back(nsr.top().second);
              else
              v2.push_back(n);
               
          }
          nsr.push({arr[i],i});
           
          }
         reverse(v2.begin(),v2.end());
        //   for(int i=0;i<n;i++)
        //   cout<<v2[i]<<" ";
        //   cout<<endl;
         int width[n];
        for(int i=0;i<n;i++)
        {
            width[i]=(v2[i]-v1[i]-1);
        }
        
        vector<long long>area;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max((width[i]*arr[i]),ans);
            //cout<<ans<<endl;
        }
        // //for(auto it:area)
        // // cout<<it<<" ";
         return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends