//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function
        int mod=1e9+7;
    // avoid space at the starting of the string in "move disk....."
    long long toh(int n, int s, int d, int h) {
        
        if(n==1)
        {
            cout<<"move disk "<<n<<" from rod "<<s<<" to rod "<<d<<endl;
            return 1;
        }
        long long ans=1;
        toh(n-1,s,h,d);
        // ans++;
         cout<<"move disk "<<n<<" from rod "<<s<<" to rod "<<d<<endl;
         toh(n-1,h,d,s);
        for(int i=1;i<=n;i++)
        {
            ans=(ans*2)%mod;
            
        }
        return ans-1;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.
// } Driver Code Ends