//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    void printsubsets(vector<int>& A,vector<int>&subset,vector<vector<int>>&ans,int index)
    {
        if(index==A.size())
        {
            ans.push_back(subset);
            return;
        }
        //element isnt added
        printsubsets(A,subset,ans,index+1);        
        //element is added
        subset.push_back(A[index]);
        printsubsets(A,subset,ans,index+1);
        subset.pop_back();
        
        

    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        vector<vector<int>>ans;
        vector<int>subset;
       // sort(A.begin(),A.end());
        printsubsets(A,subset,ans,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends