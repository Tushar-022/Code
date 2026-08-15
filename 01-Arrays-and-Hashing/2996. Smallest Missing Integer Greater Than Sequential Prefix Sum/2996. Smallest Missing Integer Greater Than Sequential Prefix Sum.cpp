1class Solution {
2public:
3    int missingInteger(vector<int>& nums) {
4        
5        int n=nums.size();
6        int len=1,maxi=1,sum=nums[0];  
7        // len ke corresponding sum store kr lete        
8        /// 1 2 3 2 5
9        map<int,int>m;
10        set<int>st;
11        st.insert(nums[0]);
12        m[1]=nums[0];
13        int flag=1;
14        for(int i=1;i<n;i++)
15        {
16            if(nums[i]-nums[i-1]==1 && flag==1)
17            {
18               // len++;
19                sum+=nums[i];
20            }
21            else
22                flag=0;
23            
24            st.insert(nums[i]);
25        }
26        
27        int temp=sum;
28      //  cout<<maxi<< <<temp<<endl;
29        while(sum<=1e8)
30        {
31            if(st.find(sum)==st.end())
32            {
33                return sum;
34            }
35            sum++;
36        }
37        return 0;
38    }                            // 1 2 3 2 5
39};