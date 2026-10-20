class Solution {

public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() +1, vector<int>(2, -1));
        dp[prices.size()][0] =0;
          dp[prices.size()][1] =0;
        for(int i = prices.size() -1;i>=0;i--)
        {
            for(int cond =0;cond<2;cond++)
            {
                int prof =0;
   if (cond) {
             prof = max(-prices[i] + dp[i+1][0],
                                     dp[i+1][1]);
        } else {
             prof = max(prices[i] + dp[i+1][1],
                                    dp[i+1][0]);
            }
            dp[i][cond] = prof;
        }
    }
    return dp[0][1];
    }
};