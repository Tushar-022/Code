//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int isPossible (string s)
{
    unordered_map<char,int>m;
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        m[ch]++;
        
    }
    int cnt=0;
    for(auto it:m)
    {
        if((it.second)%2!=0)
        {
            cnt++;
        }
        if(cnt>1)
        return 0;
    }
    return 1;
}