//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int cnt0=0,cnt1=0,cnt2=0;
        
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            cnt0++;
            else if(a[i]==1)
            cnt1++;
            else
            cnt2++;
        }
        //cout<<cnt0<<" "<<cnt1<<" "<<cnt2<<endl;
        int i=0;
            while(cnt0>0)
            {
                a[i]=0;
                i++;
                cnt0--;
            }
             while(cnt1>0)
            {
                a[i]=1;
                i++;
                cnt1--;
            }
             while(cnt2>0)
            {
                a[i]=2;
                i++;
                cnt2--;
            }
            
        
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends