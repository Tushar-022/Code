//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
{
        stack<char>s;
        int n=x.length();
        for(int i=0;i<n;i++)
      {
            char y=x[i];
        
        if(y=='{'||y== '['|| y=='(')
        s.push(y);
        
        else   
         {
            
            if(!s.empty())
            {
                char top=s.top();
                if(y=='}'&& top=='{'||
               y==')'&& top=='('||
               y==']'&& top=='[')
               {
                    s.pop();
               }
                else
                return false;
            }
            else
            return false;
          }
      
      }
    if(s.empty())
      return true;
}

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends