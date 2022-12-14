//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    void printsubsets(vector<int>& arr,vector<int>&subset,set<vector<int>>&s,int index)
    {
        if(index==arr.size())
        {
            s.insert(subset);
            return;
        }
        //element isnt added
        printsubsets(arr,subset,s,index+1);        
        //element is added
        subset.push_back(arr[index]);
        printsubsets(arr,subset,s,index+1);
        subset.pop_back();
    }
    
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        sort(arr.begin(),arr.end());
        vector<int>subset;
        set<vector<int>>s;
        printsubsets(arr,subset,s,0);
        
        vector<vector<int>>ans(s.begin(),s.end());
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
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
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