//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    
    bool knows(int a,int b,vector<vector<int> >& M,int n)
    {
        if(M[a][b]==1)
        return true;
        else
        return false;
        
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            s.push(i);
        }
        while(s.size()>1)
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(knows(a,b,M,n))
            s.push(b);
            else
            s.push(a);
        }
        int candidate=s.top();
        bool checkrow=false;
        int zerocnt=0;
        for(int j=0;j<n;j++)
        {
            if(M[candidate][j]==0)
            zerocnt++;
        }
        if(zerocnt==n)
      checkrow=true;
        
        bool colcheck=false;
        int onecnt=0;
        for(int i=0;i<n;i++)
        {
            if(M[i][candidate]==1)
            onecnt++;
        }
        if(onecnt==n-1)
        colcheck=true;
        if(checkrow==true && colcheck==true)
        return candidate;
        else
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends