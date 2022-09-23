class Solution {
public:
   static bool comp(string &s1,string &s2)
    {
        return s1.size()<s2.size();
    }
        
    
        bool checkpossible(string &s1,string &s2)
        {
            if(s1.size()!=s2.size()+1)
                return false;
          int first=0,second=0;
            while(first<s1.size())
            {
                if(s1.size()>second&& s1[first]==s2[second])
                { first++;
                second++;
                }
                else
                first++;
            }
            
            
            if(first-second==1)
                return true;
            return false;
        }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        int maxi=1;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(checkpossible(words[i],words[prev])&& 1+dp[prev]>dp[i])
                    dp[i]=dp[prev]+1;
                
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i]>maxi)
                maxi=max(dp[i],maxi);
        }
        return maxi;
    }
};