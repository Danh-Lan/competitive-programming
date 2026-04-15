// https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp(n+1, vector<long long>(n+1, 0));
        dp[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i][1] = (1LL * (i-1) * dp[i-1][1]) % MOD;
            dp[i][i] = 1;
            for (int j = 2; j < i; j++) {
                dp[i][j] = (dp[i-1][j-1] + (i-1) * dp[i-1][j]) % MOD;
            }
        }

        return dp[n][k];
    }
};