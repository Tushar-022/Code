//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
    bool isvalid(int*arr,int n,int k,long long mid)
    {
        long long tsum=0,cntpt=1;
        for(int i=0;i<n;i++)
        {
            tsum+=arr[i];
            if(tsum>mid)
            {
                tsum=arr[i];
                cntpt++;
                if(cntpt>k)
                return false;
            }
        }
        return true;
    }
  
    long long minTime(int arr[], int n, int k)
    {
        
         long long low=0;
         long long high=0,tsum=0;
         long long ans=INT_MAX;
        for( long long i=0;i<n;i++)
        {
            tsum+= (long long)arr[i];
            low=max(low, (long long)arr[i]);
        }
        if(k>=n)
        return low;
        high=tsum;
         long long result=9223372036854775807;
        while(high>=low)
        {
             long long mid=low+(high-low)/2;
            if(isvalid(arr,n,k,mid))
            {
                result=min(result,mid);
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends