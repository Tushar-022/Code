//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
//     long long jumpingNums(long long X) {
        
        
//     }
// };
    
    void helper(long long x,long long& ans,long long num)
    {
        if(num<=x and num>ans)
        ans=num;
        if(num>x)
        return;
        
        if(num%10!=9)
            helper(x,ans,num*10+(num%10+1));
        if(num%10!=0)
            helper(x,ans,num*10+(num%10-1));
    }
    
  public:
    long long jumpingNums(long long x) 
    {
        // code here
        
        long long ans=0;
        
        for(long long i=1;i<=9;i++)
        helper(x,ans,i);
        return ans;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends