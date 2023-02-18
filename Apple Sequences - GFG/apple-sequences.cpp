//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string s){
        
        int cnt=0,maxi=0;
        if(m>=n)
        return n;
        int i=0,j=0,ans=0,temp=m;
        while(j<n)
        {
           if(s[j]=='O')
           m--;
           
           while(m<0)
           {
               if(s[i]=='O')
               {
                   m++;
               }
                   i++;
           }
           ans=max(ans,j-i+1);
            j++; 
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends