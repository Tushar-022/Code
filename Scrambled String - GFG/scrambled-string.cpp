//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    unordered_map<string, bool> um;
    bool isScramble(string s1, string s2){

        if (s1.size() < 1) return false;
        if (s1.compare(s2) == 0) return true; // Base condition
		
        if (um.count(s1 + "#" + s2)) return um[s1 + "#" + s2]; // Memoisation
		
        int n = s1.size();
        bool flag = false;
        for (int i = 1; i < n; i++) {
            if (
				(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n-i), s2.substr(i, n-i))) // Case I
				|| 
				(isScramble(s1.substr(0, i), s2.substr(n-i, i)) && isScramble(s1.substr(i, n-i), s2.substr(0, n-i))) // Case II
				) 
			{
                flag = true;
                break;
            }
        }
        um[s1 + "#" + s2] = flag;
        return flag;
 
        
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends