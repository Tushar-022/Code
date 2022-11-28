//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
// class Solution{
// public:
// 	vector<int> findSubarray(int a[], int n) {
// 	    // code here
// 	}
//};
//User function template for C++
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    
	    int prev=0, sum=0, temp=0, idx=0, len=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]<0)
	        {
	           if(sum<temp)
	           {
	               idx = prev;
	               sum = temp;
	               len = i-prev;
	           }
	           else if(sum==temp)
	           {
	               if(len < i-prev)
	               {
	                   idx = prev;
	               }
	           }
	           prev = i+1;
	           temp=0;
	        }
	        else
	        {
	            temp += a[i];
	        }
	    }
	    
	    if(sum<temp)
	    {
	        idx = prev;
	        sum = temp;
	        len = n-prev;
	    }
	    else if(sum==temp)
	    {
	        if(len < n-prev)
	        idx=prev;
	    }
	    
	    vector<int> ans;
	    
	    for(int i=idx;i<idx+len;i++)
	    {
	        ans.push_back(a[i]);
	    }
	    
	    if(len==0)
	    ans.push_back(-1);
	    return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

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
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends