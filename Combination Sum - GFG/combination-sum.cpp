//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
        void findcombinations(int i,vector<int>&A,vector<vector<int>>&ans,int B,vector<int>&t)
        {
    
            if(i==A.size())
            {
                if(B==0)
                ans.push_back(t);
                return;
            }
          
            if(i>0)
          {  if(B>=A[i]& A[i]!=A[i-1])
           {
              t.push_back(A[i]);   
               findcombinations(i,A,ans,B-A[i],t);
               t.pop_back();
           }
           findcombinations(i+1,A,ans,B,t);
          }
          else
          {
              if(B>=A[i])
           {
              t.push_back(A[i]);   
               findcombinations(i,A,ans,B-A[i],t);
               t.pop_back();
           }
           findcombinations(i+1,A,ans,B,t);
          }
           
        }
        
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        
        sort(A.begin(),A.end());
        vector<vector<int>>ans;
        vector<int>t;
        findcombinations(0,A,ans,B,t);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends