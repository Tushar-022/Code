//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
       unordered_map<char,char>m1;
       unordered_map<char,bool>m2;
       if(str1.length()!=str2.length())
       return false;
       for(int i=0;i<str1.length();i++)
       {
           char ch1=str1[i];
           char ch2=str2[i];
           if(m1.find(ch1)!=m1.end())
           {
               if(m1[ch1]!=ch2)
               return false;
           }
           else
           {
               if(m2.find(ch2)!=m2.end())
               return false;
               else
               {
                   m1[ch1]=ch2;
                   m2[ch2]=true;
               }
           }
           
       }
       return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends