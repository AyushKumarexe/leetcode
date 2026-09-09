class Solution {
    int fun(int i, int t, vector<int>& nums, vector<vector<int>>& dp, int off, vector<int>& prefix) {
        if (abs(t) > prefix[i]) return 0;   // prune: unreachable, avoids OOB
        if (i == 0) {
            int ways = 0;
            if (nums[0] + t == 0) ways++;
            if (-nums[0] + t == 0) ways++;
            return ways;
        }
        if (dp[i][t + off] != -1) return dp[i][t + off];
        int left  = fun(i - 1, t + nums[i], nums, dp, off, prefix);
        int right = fun(i - 1, t - nums[i], nums, dp, off, prefix);
        return dp[i][t + off] = left + right;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + nums[i];

        int sum = prefix[n - 1];
        if (abs(target) > sum) return 0;

        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));
        return fun(n - 1, target, nums, dp, sum, prefix);
    }
};