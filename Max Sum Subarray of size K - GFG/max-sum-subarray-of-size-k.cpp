//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        
        long sum=0;
        int size=0;
        int i=0,j=0;
        long maxi=INT_MIN;
        while(j<n)
        {
            if(j-i+1>k)
            {
                sum-=arr[i];
                i++;
            }
            
            
            sum+=arr[j];
              maxi=max(maxi,sum);      
            
            
            j++;
            
        }
        return maxi;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends