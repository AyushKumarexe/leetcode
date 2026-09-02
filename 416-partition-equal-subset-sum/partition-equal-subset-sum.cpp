class Solution {
 bool dfs(int i,int sum, vector<vector<int>>&dp,vector<int>& nums)
 {
  if(sum ==0)return true;
  if(i==0)return sum== nums[0];
  if(dp[i][sum]!=-1)return dp[i][sum];
    bool left = false;
  if(nums[i] <= sum)
   left =  dfs(i-1,sum-nums[i],dp, nums);
  int right = dfs(i-1,sum,dp,nums);
  return dp[i][sum] = left||right; 
 }
public:
    bool canPartition(vector<int>& nums) {
     int sum =0;
     for(int i =0;i<nums.size();i++)
     {
     sum+=nums[i];   
     } 
     if(sum%2 !=0)return false; 
      sum = sum/2;
     vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));
    return dfs(nums.size()-1,sum,dp,nums); 
    }
};