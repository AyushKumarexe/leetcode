class Solution {
    int fun(int i ,int j ,vector<int>& nums1,vector<int>& nums2,vector<vector<int>>&dp)
    {
    if(i<0||j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(nums1[i]==nums2[j])
    return dp[i][j] = 1 + fun( i-1, j-1, nums1, nums2,dp);
    return dp[i][j] = max(fun( i, j-1, nums1, nums2,dp),fun( i-1, j, nums1, nums2,dp));
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
     vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),-1));
     return  fun( nums1.size()-1, nums2.size()-1, nums1, nums2,dp);  
    }
};