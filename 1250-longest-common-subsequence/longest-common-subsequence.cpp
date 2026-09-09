class Solution {
    int fun(int i,int j ,string &text1,string &text2,vector<vector<int>>&dp)
    {
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) 
        {
   return dp[i][j] = 1+fun(i-1,j-1,text1,text2,dp);
        }
    return dp[i][j] = max(fun(i-1,j,text1,text2,dp),fun(i,j-1,text1,text2,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return  fun(text1.size()-1,text2.size()-1,text1,text2,dp);
    }
};