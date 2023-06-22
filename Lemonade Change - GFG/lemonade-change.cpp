//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

        // code here
      class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int fiveCnt = 0, tenCnt = 0;
        for(auto bill: bills){
            if(bill == 5) fiveCnt++;
            else if(bill == 10){
                if(fiveCnt <= 0) return false;
                tenCnt++; fiveCnt--;
            }
            else{
                if(tenCnt == 0){
                    if(fiveCnt < 3) return false;
                    fiveCnt -= 3;
                }
                else if(fiveCnt <= 0){
                    return false;
                }
                else{
                    fiveCnt--; tenCnt--;
                }
            }
        }
        return true;
    }
};
    

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends