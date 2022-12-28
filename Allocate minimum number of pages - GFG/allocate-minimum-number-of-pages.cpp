//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool isvalid(int* arr,int n,int m,int mid)
    {
        int cntstudents=1;
        int pagesum=0;
        for(int i=0;i<n;i++)
        {
            pagesum+=arr[i];
            if(pagesum>mid)
            {
                pagesum=arr[i];
                cntstudents++;
                if(cntstudents>m)
                return false;
            }
            
        }
        return true;
    }
    
    int findPages(int arr[], int n, int m) 
    {
        int pagesum=0,maxi=0;
        for(int i=0;i<n;i++)
        {
            pagesum+=arr[i];
            maxi=max(maxi,arr[i]);
        }
        //cout<<pagesum<<" "<<maxi<<endl;
         int low=maxi,high=pagesum,result=INT_MAX;
         while(high>=low)
         {
             if(m>n)
             return -1;
             
             int mid=low+(high-low)/2;
            // cout<<mid<<" "<<endl;
             if(isvalid(arr,n,m,mid))
             {
                 result=min(result,mid);
                 //cout<<result<<" "<<endl;;
                 high=mid-1;
             }
             else
             low=mid+1;
         }
         return result;
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends