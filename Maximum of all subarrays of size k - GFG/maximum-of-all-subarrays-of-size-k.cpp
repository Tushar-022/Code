//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int>ans;
    //     int index=0;
    //     priority_queue<int>pq;
    //     for(int i=0;i<k;i++)
    //     {
    //         pq.push(arr[i]);
    //     }
    //     for(int j=k;j<n;j++)
    //       {
    //         ans.push_back(pq.top());
    //         //ans.push_back(pq.top());
            
    //         pq.push(arr[j]);
    //       }
    //       pq.pop(arr[index++]);
    //   }
    //     // while(!pq.empty())
    //     // {
    //     //     arr[index++]=pq.top();
            
    //     //     pq.top();
    //     // }
    // int t=INT_MIN;
    // int j=0;
    // while(j<n)
    // {
    //     {
    //         if(j-i+1<k)
    //         j++;
    //         else if(j-i+1==k)
    //         {
    //             maxi=max(t,sum);
    //         }
    //     }
    // }
    
    //     return ans;
    
      deque<int>q;
        int i=0,j=0;
        vector<int>res;
        while(j<n){
            while(!q.empty() && q.back()<arr[j]) q.pop_back();
            q.push_back(arr[j]);
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                res.push_back(q.front());
                if(q.front()==arr[i]) q.pop_front();
                i++;
                j++;
            }
        }
        return res;
    
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends