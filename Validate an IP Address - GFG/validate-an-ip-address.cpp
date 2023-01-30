//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
    
    bool check(string a)
    {
        if(a.size()>3|| a.size()==0)
        {
           // cout<<1<<endl;
            return false;
        }   
        if(a.size()>1 && a[0]=='0')
        {
            //cout<<2<<endl;
            return false;
        }
        for(int i = 0;i < a.size();i++){
            if(a[i]<'0'||a[i]>'9'){
                return false;
            }
        }
        if(stoi(a)>=0 && stoi(a)<=255){
            return true;
        }
        else{
            return false;
        }
    }
        int isValid(string s) {
        int n=s.length();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
          if(s[i]=='.')
          cnt++;
        }
        if(cnt!=3)
        return 0;
        if (s[0]=='.')
        return 0;
        string a,b,c,d;
         cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='.')
            {
                cnt++;
            }
            else{
                if(cnt==0)
                {
                    a+=s[i];
                }
               else if(cnt==1)
                {
                    b+=s[i];
                }
                else if(cnt==2)
                {
                    c+=s[i];
                }
               else if(cnt==3)
                {
                    d+=s[i];
                }
            }
               
        }
       // cout<<a<<""<<b<<" "<<c<<" "<<d<<endl;
        // cout<< check(a)<<endl;
        // cout<<"Hi"<<endl;
        //  cout<< check(b)<<endl;
        //  cout<<"Hi"<<endl;
        //   cout<< check(c)<<endl;
        //   cout<<"Hi"<<endl;
        //   cout<< check(d)<<endl;
        //   cout<<"Hi"<<endl;
           if(check(a)&& check(b)&& check(c)&& check(d)==1)
           return 1;
           else
           return 0;
        }
        
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends