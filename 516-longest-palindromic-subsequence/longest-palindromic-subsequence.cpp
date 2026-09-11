class Solution {
public:
    int longestPalindromeSubseq(string s) {
         vector<vector<int>>dp(s.size() +1,vector<int>(s.size()+1,-1));
         string text1 = s;
        reverse(s.begin(),s.end());
        for(int i =0;i<=s.size();i++)
        {
          dp[i][0] =0;  
        }
           for(int i =0;i<=s.size();i++)
        {
          dp[0][i] =0;  
        }
      for(int i =1;i<=s.size();i++)
      {
        for(int j =1;j<=s.size();j++)
        {
          if(text1[i-1]==s[j-1]) 
        {
   dp[i][j] = 1+ dp[i-1][j-1];
        }
        else 
     dp[i][j] = max(dp[i][j-1],dp[i-1][j]);   
        }
      }
        return dp[s.size()][s.size()];
    }
};