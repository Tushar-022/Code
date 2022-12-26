//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        int medianPos = (R*C+1)/2 ; //or (R*C)/2 +1
        int low = 1, high = 2000;
        while(low<=high){ // obviously because it could be a single number only.
            int mid = (low+high)/2;
            //now finding the position of mid in hypothetically sorted array of matrix elements
            int midPos = 0;
            for(int i=0;i<R;i++){
                vector<int> arr = matrix[i];
                auto ptr = upper_bound(arr.begin(),arr.end(),mid);
                int upIndex = ptr - arr.begin();
                midPos += upIndex ;
            }
            // cout<< "for mid = "<<mid<<" ,it's position is= "<<midPos<<endl;
            if(midPos<medianPos) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends