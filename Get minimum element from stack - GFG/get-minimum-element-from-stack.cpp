//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

// class Solution{
//     int minEle;
//     stack<int> s;
//     public:
    
//       /*returns min element from stack*/
//       int getMin(){
           
//           if(s.empty())
//           return -1;
//           return minEle;
//       }
       
//       /*returns poped element from stack*/
//       int pop(){
           
//           if(s.empty())
//           return -1;
//           if(s.top()>minEle)
//           {  int p=s.top();
//               s.pop();
//               return p;
//           }
//           else if(minEle>s.top())
//           {
               
//               minEle=2*minEle-s.top();
//                 s.pop();
                
//           }
       
//       }
       
//       /*push element x into the stack*/
//       void push(int x){
//             if(s.size()==0)
//         {
//             s.push(x);
//             minEle=x;
//         else
//         {
//             if(s.size>0 && minEle>x)
//         {
//             s.push(2*x-minEle);
//             minEle=x;
//         }
//         else
//         {
//             s.push(x);
//         }

//       }
//};
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(s.empty())
            return -1;
            return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(s.empty()){
              return -1;
          }
          int x=s.top();
          s.pop();
          if(x<=minEle){
              int res=minEle;
              minEle=2*minEle-x;
              return res;
          }
          else{
              return x;
          }
          //Write your code here
      }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           if(s.empty())
           {
               minEle=x;
               s.push(x);
               return;
           }
           
           if(x<=minEle)
           {
               s.push(2*x-minEle);
               minEle=x;
           }
           else
            s.push(x);
       }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends