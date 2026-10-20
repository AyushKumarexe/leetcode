class Solution {
    int dps(int i, int cond, vector<int>& prices, vector < vector<int>> & dp) {
        if (i == prices.size())
            return 0;
        if (dp[i][cond] != -1)
            return dp[i][cond];
        if (cond) {
            return dp[i][cond] = max(-prices[i] + dps(i + 1, 0, prices, dp),
                                     dps(i + 1, 1, prices, dp));
        } else {
            return dp[i][cond] = max(prices[i] + dps(i + 1, 1, prices, dp),
                                     dps(i + 1, 0, prices, dp));
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return dps(0, 1, prices, dp);
    }
};