//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& a, int N){
      //Code here.
      long long int ans=0;
      int sum=0;
      for(int i=0;i<a.size();i++)
      {
          sum+=a[i]; // calculating no.of wine to buy at given index.
          ans+=abs(sum); // cost of transport wine
      }
      return ans;
  }
};




//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends