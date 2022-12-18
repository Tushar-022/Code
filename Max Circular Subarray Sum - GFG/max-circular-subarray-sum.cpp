//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
     int kadane(int*arr,int num)
     {
     int csum=arr[0];
        int osum=arr[0];
        for(int i=1;i<num;i++)
        {
            if(csum>=0)
            csum+=arr[i];
            else
            csum=arr[i];
            if(csum>osum)
            osum=csum;
        }
        return osum;
     }
    
    int circularSubarraySum(int arr[], int num){
        int cnt=0;
        int maxi=INT_MIN;
        for(int i=0;i<num;i++)
        {
            if(arr[i]<0)
           {
               cnt++;
                maxi=max(maxi,arr[i]);
           } 
        }
        if(cnt==num)
        return maxi;
        int wrapsum,nonwrapsum;
        nonwrapsum=kadane(arr,num);
        int ttsum=0;
        for(int i=0;i<num;i++)
        {
            ttsum+=arr[i];
            arr[i]=-arr[i];
        }
        wrapsum=ttsum+kadane(arr,num);
        //cout<<nonwrapsum<<endl;
        //cout<<wrapsum<<endl;
        return max(wrapsum,nonwrapsum);
       
    }
};
    

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends