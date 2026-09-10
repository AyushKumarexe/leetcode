class Solution {
    int fun(int i ,int j ,string nums1,string nums2,vector<vector<int>>&dp)
    {
    if(i<0||j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(nums1[i]==nums2[j])
    return dp[i][j] = 1 + fun( i-1, j-1, nums1, nums2,dp);
    return dp[i][j] = max(fun( i, j-1, nums1, nums2,dp),fun( i-1, j, nums1, nums2,dp));
    }
public:
    int minDistance(string word1, string word2) {
       vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
     int num =  fun( word1.size()-1, word2.size()-1, word1, word2,dp); 
     return word1.size() +word2.size() - 2*num;
    }
};