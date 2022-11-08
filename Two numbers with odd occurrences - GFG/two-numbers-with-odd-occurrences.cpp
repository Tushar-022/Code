//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
// class Solution{
//     public:
//     vector<long long int> twoOddNum(long long int Arr[], long long int N)  
//     {
//         map<int,int>m;
//         for(int i=0;i<N;i++)
//         m[Arr[i]]++;
//         for(auto it: m)
//         {
//             if(m[arr[i]])
//         }
//     }
// };

class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long int XOR=0;

        for(long long int i=0;i<N;i++)

        {

            XOR=XOR^Arr[i];

        }

        

        long long int n=(XOR&(~(XOR-1))),a=0,b=0;

        for(long long int i=0;i<N;i++)

        {

            if((n&Arr[i])==0)

            a=a^Arr[i];

            else

            b=b^Arr[i];

        }

        

        if(a>b)

        return {a,b};

        else

        return {b,a};
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends