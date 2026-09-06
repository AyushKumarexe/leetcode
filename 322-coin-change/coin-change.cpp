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
   int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e8));
        
        // Base case: i == 0, only first coin available
        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0)
                dp[0][target] = target / coins[0];
            // else stays 1e8 (impossible)
        }
        
        // Fill rest of the table
        for (int i = 1; i < n; i++) {
            for (int target = 0; target <= amount; target++) {
                int skip = dp[i - 1][target];
                int take = 1e8;
                if (coins[i] <= target) {
                    take = 1 + dp[i][target - coins[i]];
                }
                dp[i][target] = min(skip, take);
            }
        }
        
        int ans = dp[n - 1][amount];
        return ans >= 1e8 ? -1 : ans;
    }
};