//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Solution{
    // public:
    // string rearrange (string S, int N)
    // {
        
    // }
//};
class Solution{
    public:
    string rearrange (string S, int N)
    {
        int vc = 0, cc = 0;
        for(int i = 0; i<N; i++)
        {
            if(S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u')
            {
                vc++;
            }
            else cc++;
        }
        
        if(abs(vc-cc)>1) return "-1";
        else
        {
            string ans = "";
            map<char,int>mpv,mpc;
            for(int i = 0; i<N; i++)
            {
                if(S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u')
                {
                    mpv[S[i]]++;
                }
                else mpc[S[i]]++;
            }
            
            string vowel = "", cons = "";
            for(auto it:mpv)
            {
                while(it.second--) vowel += it.first;
            }
            for(auto it:mpc)
            {
                while(it.second--) cons += it.first;
            }
            
            int i = 0, j = 0, f = 0;
            if(vc>cc)
            {
                ans += vowel[i];
                i++;
                f = 1;
            }
            else if(vc<cc)
            {
                ans += cons[j];
                j++;
            }
            else
            {
                if(vowel[0]<cons[0])
                {
                    ans += vowel[0];
                    i++;
                    f = 1;
                }
                else
                {
                    ans += cons[j];
                    j++;
                }
            }
            while(i<vowel.size() && j<cons.size())
            {
                if(f)
                {
                    ans += cons[j];
                    j++;
                    f = 0;
                }
                else
                {
                    ans += vowel[i];
                    i++;
                    f = 1;
                }
            }
            while(i<vowel.size())
            {
                ans += vowel[i];
                i++;
            }
            while(j<cons.size())
            {
                ans += cons[j];
                j++;
            }
            return ans;
        }
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends