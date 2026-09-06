class Solution {
  
public:
    int coinChange(vector<int>& coins, int amount) {
   int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e8));
        
        // Base case: i == 0, only first coin available
        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0)
                dp[0][target] = target / coins[0];
            
        }
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