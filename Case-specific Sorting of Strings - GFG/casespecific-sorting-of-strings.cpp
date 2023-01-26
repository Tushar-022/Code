//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string s, int n)
    {
        vector<char>v1,v2;
        for(int i=0;i<n;i++)
        {
            if(s[i]-'a'>=0)
            v1.push_back(s[i]);
            else
            v2.push_back(s[i]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        // for(auto it:v1)
        // cout<<it<<" ";
        // cout<<endl;
        string temp;
       
       int i=0,j=0,k=0;
       
    while( i<n)
    {
        if(s[i]-'a'>=0 )
        {
            temp+=v1[k];
            i++;
            k++;
        }
        else
        {
            temp+=v2[j];
            i++;
            j++;
        }
        
    }
       return temp;
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends