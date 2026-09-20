1class Solution {
2public:
3    int m,n;
4
5    int solve(string s,string t,int i,int j,vector<vector<int>>&dp)
6    {
7        if(j<0)
8        return 1;
9
10        if(i<0)
11        return 0;
12
13        if(dp[i][j]!=-1)
14        return dp[i][j];
15
16
17        int pick=0,npick=0;
18        if(s[i]==t[j])
19        pick= solve(s,t,i-1,j-1,dp)+solve(s,t,i-1,j,dp);
20        else
21        {
22            npick= solve(s,t,i-1,j,dp);
23        }
24        return dp[i][j]= pick+npick;
25    }
26    int numDistinct(string s, string t) {
27        m=s.size();
28        n=t.size();
29        if(n>m)
30        return 0;
31        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
32        return solve(s,t,m-1,n-1,dp);
33    }
34};