//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution{ 
    
public:
    vector<int> minPartition(int N)
    {    vector<int>v={2000,500,200,100,50,20,10,5,2,1} ;
           int i =0;
           vector<int>v1;
           while(i<=9){
               if(v[i]>N)
               i++ ;
               else{
                  N= N-v[i] ;
                  v1.push_back(v[i]) ;
               }
           }
           return v1;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends