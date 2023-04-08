//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void permutation(int index,string s,set<string>&u)
	{
	    if(index==s.size())
	    {
	       // cout<<s<<" ";
	        u.insert(s);
	        return;
	    }
	    for(int i=index;i<s.size();i++)
	    {
	       
	        swap(s[index],s[i]);
	        permutation(index+1,s,u);
	        swap(s[index],s[i]);
	    }
	    
	   
	}
		vector<string>find_permutation(string S)
		{
		    string s=S;
		    set<string>u;
		    permutation(0,s,u);
		    vector<string>ans(u.begin(),u.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends