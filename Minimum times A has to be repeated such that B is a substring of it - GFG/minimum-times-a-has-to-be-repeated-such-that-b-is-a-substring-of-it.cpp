//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// class Solution {
//   public:
    // int minRepeats(string A, string B) {
    //     vector<int>v1(26,0),v2(26,0);
    //     for(int i=0;i<B.length();i++)
    //     {
    //         v1[B[i]-'a']++;
    //     }
    //      for(int i=0;i<A.length();i++)
    //     {
    //         v2[A[i]-'a']++;
    //     }

      
        
    //     for(int i=0;i<26;i++)
    //     {
    //         if(v1[i]>0 && v2[i]==0)
    //       {
               
    //         return -1;
    //       }
    //     }
    //     // for(int i=0;i<26;i++)
    //     // {
    //     //     if(v2[i]>0 && v1[i]==0)
    //     //   {
               
    //     //     return -1;
    //     //   }
    //     // }
    //     int cnt=1;
    //     int m=A.length();
    //     int n=B.length();
    //     // if(m%n!=0)
    //     // return -1;
    //     //if(m%)
    //     int i=0,j=0;
    //     bool flag1=0,flag2=0;
    //     while(j<n)
    //     {
    //         //cout<<"Ho"<<endl;
    //         if(B[j]==A[i])
    //         {
    //             flag1=1;
    //             if(i==m-1)
    //             {
    //                 cnt=cnt+1;
    //                 cout<<cnt<<endl;
    //                 j++;
    //                 i=0;
    //                 flag2=1;
    //             }
    //           else 
    //           {
    //               i++;
    //               j++;
                   
    //           }
               
    //         }  
    //         else if(flag1==0 && flag2==0 )
    //         i++;
    //         else if(flag2==1 && flag1==1 )
    //         {
    //             if(j==n-1 )
    //              return cnt;
    //              else
    //             return -1;
    //         }
    //         else if(flag2==0 && flag1==1)
    //         {
    //             j=0;
    //             i++;
    //             flag1=0;
    //         }
            
    //     }
    //     if(i==0 && j!=n-1)
    //     {
    //         cout<<"Hi"<<endl;
    //         return cnt-1;
    //     }
    //     else
    //     {
    //         cout<<"hi"<<endl;
    //         return cnt;
    //     }
    
    //User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        // code here
        if(B.size()==0) return 0;
        int ans=1;
        string s=A;
        while(s.size() < B.size())
        {
            s+=A;
            ans++;
        }
        if(s.find(B)!=-1) return ans;
        s+=A;
        ans++;
        if(s.find(B)!=-1) return ans;
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends