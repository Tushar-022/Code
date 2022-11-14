//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

// class Solution{   
// public:
//     int numberOfSubsequences(string S, string W){
        
//         int cnt=0;
//         int m=S.length();
//         int n=W.length();
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<k;j++)
//             {
//                 if(W[j]==S[i])
//               {
//                   j++;
//                   i++;
//                   cnt++;
//                   if(cnt==)
//               }
//                 else
//                 i++;
                
//             }
            
//         }
  //  }
//};


class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        vector<bool>vis(S.size()+1,true);
        int ans=0;
        for(int i=0;i<S.size()-W.size()+1;i++){
            int index=0;
            for(int j=i;j<S.size();j++){
                if(vis[j] && W[index]==S[j]){
                    vis[j]=false;
                    index++;
                }
                if(index==W.size()){
                    ans++;
                    break;
                }
            }
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
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends