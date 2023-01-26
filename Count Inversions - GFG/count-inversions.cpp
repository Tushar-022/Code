//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//  using ll=long long;

// class Solution{
//   public:
     
     
//      long long cntmerge(long long *arr,long long l,long long m,long long r)
//      {
//          long long n1=m-l+1;
//          long long n2=r-m;
//          long long left[n1],long long right[n2];
//          for(int i=0;i<n1;i++)
//          {
//              left[i]=arr[l+i];
             
//          }
//          for(int i=n1;i<n;i++)
//          {
             
//              right[i]=arr[n1+i];
             
//          }
         
//          long long res=0,i=0,j=0,k=l;
//          while(i<n1 && j<n2)
//          {
             
//              if(left[i]<=right[j])
//              {
//                  arr[k++]=left[i++];
//              }
//              else
//              {
//                  arr[k++]=right[j++];
//              }
//          }
         
         
//      }
     
     
//     long long int inversionCount(long long arr[], long long n)
//     {
    
//     long long low=0,high=n-1;
    
//     long long ans=0;
//     if(r>l)
//     {
//         long long mid=low+(high-low)/2;
//         ans+=inversionCount(arr,low,mid);
//         ans+=inversionCount(arr,mid+1,high);
//         ans+=cntmerge(arr,low,mid,high);
//     }
    
//     }

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[],int s,int mid,int e,long long temp[]){
        long long int ans=0;
        int i=s,j=mid+1,k=s;
        while(i<=mid&&j<=e){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }
            else{
                temp[k++]=arr[j++];
                ans+=(mid+1-i);
            }
        }
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=e){
            temp[k++]=arr[j++];
        }
        for(int i=s;i<=e;i++){
            arr[i]=temp[i];
        }
        return ans;
    }
    long long int mergesort(long long arr[],int s,int e,long long temp[]){
        long long int ans=0;
        int mid;
        if(s<e){  //                its if
             mid=s+(e-s)/2;
            ans+=mergesort(arr,s,mid,temp);
            ans+=mergesort(arr,mid+1,e,temp);
            ans+=merge(arr,s,mid,e,temp);
        }
        return ans;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        return mergesort(arr,0,N-1,temp);
    }

};



//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends