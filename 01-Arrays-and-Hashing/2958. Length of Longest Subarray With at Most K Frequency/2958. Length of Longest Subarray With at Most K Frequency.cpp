1class Solution {
2public:
3    int maxSubarrayLength(vector<int>& s, int k) {
4      map<int,int>m;
5        int i=0,j=0,n=s.size(),len=0;
6
7        while(i<n)
8        {
9
10            m[s[i]]++;
11
12            while(m[s[i]]>k)
13            {
14              m[s[j]]--;
15             if(m[s[j]]==0)
16              {
17                m.erase(s[j]);
18              }
19              
20              j++;
21            }
22
23             len=max(len,i-j+1);
24             i++;
25
26        }
27         
28        return len;
29
30    }
31};
32// <=k
33// nums=1,2,3,1,2,3,1,2
34// k=2
35// 1,2,3,1,2,3