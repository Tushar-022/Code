//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    vector<int>lex(vector<int>a,vector<int>b)
    {
        for(int i=0;i<4;i++)
        {
            if(a[i]>b[i])
            return b;
          else if(b[i]>a[i])
        return a;
        }
      
    }
  
  
    vector<int> satisfyEqn(int A[], int N) {
        vector<int>ans(4,INT_MAX);
        unordered_map<int,vector<int>>m;
        int sum=0;
         vector<int>t(4,-1);
        for(int i=0;i<N-1;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                sum=A[i]+A[j];
                if(m.find(sum)!=m.end())
                {
                    if(m[sum][0]!=i && m[sum][0]!=j && m[sum][1]!=i && m[sum][1]!=j)
                    {
                        vector<int>temp={m[sum][0],m[sum][1],i,j};
                        ans=lex(ans,temp);
                    }
                }
                
                else
                m[sum]={i,j};
            }
        }
                // for(int i=0;i<4;i++)
                        // {
                        // if(ans[i]>temp[i])
                        // {
                        //     ans=temp;
                        //     //return ans;
                        // }
                        // else
                        // {
                           
                        //     return t;
                        // }
                        
        //             }

        //         }
        //             m[sum]={i,j};
        //     }
            
        // }
        if(ans[0]!=INT_MAX)
        return ans;
        else
        return t;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends