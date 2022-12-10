//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends

string buildLowestNumber(string s, int k)
{
    //code here.
    int j=0,i;
    for(i=1;i<s.size();i++)
    {
        while(k && j>=0 && s[j]>s[i])k--,j--;
        j++;
        s[j]=s[i];
    }
    j-=k;
    i=0;
    k=j;
    while(s[i]=='0' && i<k)i++,j--;
    return s.substr(i,j+1);
}