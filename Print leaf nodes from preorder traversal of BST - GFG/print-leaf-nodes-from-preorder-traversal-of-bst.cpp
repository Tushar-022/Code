//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
        vector<int> leafNodes(int arr[],int N) {
         vector<int> ans;
        stack<int> st;
        st.push(arr[0]);
        for(int i = 1 ; i < N ; i++){
            if(arr[i] < st.top()){
                st.push(arr[i]);
            }else{
                int ele = st.top();
                int count = 0;
                while(!st.empty() && st.top() < arr[i]){
                  st.pop();
                  count++;
                } 
                if(count > 1) ans.push_back(ele);
                st.push(arr[i]);
                
            }
        }
        if(!st.empty()){
            ans.push_back(st.top());
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends