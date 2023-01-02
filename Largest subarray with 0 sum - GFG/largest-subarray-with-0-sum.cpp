//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        unordered_map<long long,long long>m;
        long long sum=0,maxi=0;
        for( long long i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==0)
             maxi=i+1;
            else
            {
                if(m.find(sum)!=m.end())
                {
                    maxi=max(maxi,i-m[sum]);
                }
                else
                m[sum]=i;
            }
        }
        return (int) (maxi);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends