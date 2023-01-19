//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &nums, int n ) {
        
        // unordered_map<long long,long long>m;
        // long long cnt=0,sum=0;
        // for(int i=0;i<n;i++)
        // {
        //     m[sum]++;
        //     sum+=arr[i];
        //     cnt+=m[sum];  // jitni baar vahi sum aaya increase the  count
        // }
        // return cnt;
         unordered_map<long long,long long>m;
        long long cnt=0,sum=0;
        //int n=nums.size();
        m[0]=1;
        long long i=-1;
        while(i<n-1)
        {
            i++;
            sum+=nums[i];
            if(m.find(sum)!=m.end())
            {
                cnt+=m[sum];
                m[sum]++;
            }
            else
            {
                m[sum]=1;
            }
        }
        return cnt;
        
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
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends