//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// class Solution {
// public:

    // string isPrime(int N,int i)
    // {
    //     for(int i=0;i<sqrt(N);i++)
    //     if(N%i==0)
        
    // }
    
      // bool isPrime(int n)
    // {
    //     if (n <= 1)
    //         return false;
     
    //     for (int i = 2; i <= sqrt(n); i++) {
    //         if (n % i == 0)
    //             return false;
    //     }
     
       // return true;
    // }
    // string isSumOfTwo(int N){
    //     string s="No";
    //     for(int i=0;i<N;i++)
    //     {
    //         if(isPrime(i) && isPrime(N-i))
    //         s="Yes";
    //         break;
    //     }
    //     return s;
    // }
//};

class Solution {
public:
        bool isPrime(int n)
    {
        if (n <= 1)
            return false;
     
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }
     
        return true;
    }
    string isSumOfTwo(int N){
        // code here
        string ans = "No";
        for(int i=2;i<=N;i++){
            if(isPrime(i)&& isPrime(N-i)) {
                ans = "Yes";
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends