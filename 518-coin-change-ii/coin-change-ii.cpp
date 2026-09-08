class Solution {
  int fun(int i ,int target,vector<int>&nums,vector<vector<int>>&dp)
  {
    if(target ==0)return 1;
    if(i==0)
    {
    if(target%nums[0]==0)return 1;
    else
    return 0;
    }
    if(dp[i][target]!=-1)  return dp[i][target];
  int left = fun( i -1, target,nums,dp);
  int right = 0;
  if(nums[i]<=target)
  {
    right = fun( i , target-nums[i],nums,dp);
  }
  return dp[i][target] = left +right;
  }
public:
    int change(int amount, vector<int>& coins) {
     vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1)); 
     return fun( coins.size()-1, amount,coins,dp);
    }
};