//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

// class Solution {
//   public:
//     string BalancedString(int N) {
        
        
//     }
// User function template for c++

class Solution {
  public:
    string BalancedString(int N) {
        // code here
        int n = N;
        string ans = "";
        while(N > 26){
            for(int i = 0; i < 26; i++){
                ans += 'a' + i;
            }
            N -= 26;
        }
        int rem = 26 - N;
        if(n % 2 == 0){
            int x = N/2;
            for(int i = 0; i < x; i++){
                ans += 'a' + i;
            }
            for(int i = x + rem; i < 26; i++){
                ans += 'a' + i;
            }
            return ans;
        }
        int sumOfDigits = 0;
        while(n){
            int dig = n % 10;
            if(dig % 2 != 0){
                sumOfDigits++; 
            }
            n = n / 10;
        }
        if(sumOfDigits % 2 == 0){
            int x = (N + 1)/2;
            for(int i = 0; i < x; i++){
                ans += 'a' + i;
            }
            for(int i = x + rem; i < 26; i++){
                ans += 'a' + i;
            }
            return ans;
        }
        else{
            int x = (N - 1)/2;
            for(int i = 0; i < x; i++){
                ans += 'a' + i;
            }
            for(int i = x + rem; i < 26; i++){
                ans += 'a' + i;
            }
            return ans;
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
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends