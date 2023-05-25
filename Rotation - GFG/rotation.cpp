//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int nums[], int n) {
	   // int n=nums.size();
        int low=0,high=n-1;
        while(high>=low)
       {
           int mid=low+(high-low)/2;
           if(nums[(mid+n-1)%n]>=nums[mid] && nums[mid]<=nums[(mid+1)%n])
           return mid;
            else if(nums[high]>=nums[mid])
            {
                high=mid-1;
            }  
            else if(nums[mid]>=nums[low])
            {
                low=mid+1;
            }      
       }
        return -1;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends