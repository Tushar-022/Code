//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int n)
{
     //int n=height.size();
        long long start=0,end=n-1;
        long long area=0,maxi=0;
        while(end>start)
        {
            area=min(A[start],A[end])*(end-start);
            maxi=max(area,maxi);
            //cout<<area<<endl;
            if(A[start]>A[end])
            end--;
            else
            start++;

        }
        return maxi;
    
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends