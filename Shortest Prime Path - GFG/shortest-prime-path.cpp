//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

     bool a =false;
   vector<int>isprime(10000,1); class Solution{   
public:  
  
    void seive()
    {
        for(int i=2;i<10000;i++)
        {
            for(int j=i+i;j<10000;j=j+i)
            {
                isprime[j]=0;
            }
        }
    }
    
   
    int shortestPath(int n1,int n2)
    {   
        
        if(!a)
        {
            seive();
            a=true;
        }
        
        queue<pair<int,int>>q;
        q.push({n1,0});
        vector<int>vis(10000,0);
        vis[n1]=1;
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            if(t.first==n2)
            return t.second;
            string num=to_string(t.first);
            for(int j=0;j<4;j++)
            {
                for(int k=0;k<=9;k++)
                {
                    char c='0'+k;
                    string num2=num;
                    //puraani string ke vaaste
                    num2[j]=c;
                    int temp=stoi(num2);
                    if(isprime[temp] && num2[0]!='0' && vis[temp]==0)
                    {
                        q.push({temp,t.second+1});
                        vis[temp]=1;
                    }
                }
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends