//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends

class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            vector<int>ng,ps;
            for(int i=0;i<n;i++)
            {
                if(arr[i]<0)ng.push_back(arr[i]);
                else ps.push_back(arr[i]);
            }
            int x=0;
            for(int i=0;i<ng.size();i++)
            {
                arr[i]=ng[i];
                x++;
            }
            
            for(int i=0;i<ps.size();i++)
            {
                arr[x]=ps[i];
                x++;
            }
        }
};


//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends