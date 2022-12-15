//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        
        long long mxl[n],mxr[n];
        mxl[0]=arr[0];
        for(long long i=1;i<n;i++)
        {
            mxl[i]=max(mxl[i-1],(long long)arr[i]);
        }
        
        mxr[n-1]=arr[n-1];
        for(long long i=n-2;i>=0;i--)
        {
            mxr[i]=max(mxr[i+1],(long long)arr[i]);
        }
        vector<long long>v;
        for(long long i=0;i<n;i++)
        v.push_back(min(mxl[i],mxr[i])-(long long)arr[i]);
        
        long long ans=0;
        for(long long i=0;i<n;i++)
        {
            ans+=v[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends