class Solution {
    int dfs(int i ,int target,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(target ==0) return 0;
    if(i==0)
    {
        if(target % nums[0]==0)return target/nums[0];
        else
        {
        return   1e8;
        }
    }
    if(dp[i][target]!= INT_MAX) return dp[i][target];
        int left = 0 + dfs(i -1 ,target,nums,dp);
        int right = INT_MAX;
        if(nums[i]<=target)
        {
            right = 1 +  dfs( i  ,target -nums[i],nums,dp); 
        }
        return dp[i][target] = min(left,right);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
       vector<vector<int>>dp(coins.size(),vector<int>(amount +1,INT_MAX));
       int ans =  dfs(coins.size()-1,amount,coins,dp);
        return ans >= 1e8 ? -1 : ans;
    }
};