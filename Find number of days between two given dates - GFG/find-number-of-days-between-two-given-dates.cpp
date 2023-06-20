//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int leapyears(int y,int m){
        int years=y;
        if(m<=2)years--;
        return years/4-years/100+years/400;
  }
  
    int noOfDays(int d1, int m1, int y1, int d2, int m2, int y2) {
        
        // code here
        int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        int n1=0,n2=0;
        n1=d1+y1*365;
        for(int i=0;i<m1-1;i++){
            n1+=days[i];
        }
        n1+=leapyears(y1,m1);
        n2=d2+y2*365;
        for(int i=0;i<m2-1;i++){
            n2+=days[i];
        }
        n2+=leapyears(y2,m2);
        
        return abs(n2-n1);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int d1,d2,m1,m2,y1,y2;
        
        cin>>d1>>m1>>y1;
        cin>>d2>>m2>>y2;

        Solution ob;
        cout << ob.noOfDays(d1,m1,y1,d2,m2,y2) << endl;
    }
    return 0;
}
// } Driver Code Ends