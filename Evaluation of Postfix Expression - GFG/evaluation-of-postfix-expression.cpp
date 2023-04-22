//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        stack<int>st;
        int i=0,n=s.size();
        while(i<n)
        {
            if(isdigit(s[i]))
            st.push(s[i]-'0');
            
            else if(s[i]=='+')
            {
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                st.push(t1+t2);
            }
            else if(s[i]=='-')
            {
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                st.push(t2-t1);
            }
            else if(s[i]=='*')
            {
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                st.push(t1*t2);
            }
            else if(s[i]=='/')
            {
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                st.push(t2/t1);
            }
            i++;
           
          // cout<<st.top()<<" ";
        }
        //for(a)
        //return 0;
        // for(auto it:st)
        // cout<<it<<" ";
        return st.top();
        
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends