//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*
str: string in which pattern we have to find pattern.
text: pattern needs to searched.
*/

bool searchPattern(string str, string pat)
{
    int n=str.length();
    int m =pat.length();
    int t[n+1][m+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0 ||j==0)
                t[i][j]=0;
           else
            {
               if(str[i-1]==pat[j-1])
                    t[i][j]=1+t[i-1][j-1] ;
                    else
                    t[i][j]=0; 
            }
          }
       }
                
                int mx=INT_MIN;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                mx=max(mx,t[i][j]);
            }
        }
        //cout<<mx<<endl;
        if(mx==m)
        return true;
        else
        return false;
        
 
}



//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    
    while(t--)
    {
        string str, pat;
        cin>>str;
        cin>>pat;
        
        if(searchPattern(str, pat) == true)
            cout << "Present" <<endl;
        else cout << "Not present" <<endl;
    }
}


// } Driver Code Ends