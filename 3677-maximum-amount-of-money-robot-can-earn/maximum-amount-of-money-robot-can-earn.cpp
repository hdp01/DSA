class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(3, -1e17)));

        dp[0][0][2] = coins[0][0];
        dp[0][0][1] = (coins[0][0] < 0) ? 0 : coins[0][0];
        dp[0][0][0] = dp[0][0][1];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                for (int k = 0; k < 3; k++) {
                    long long prev = -1e17;
                    if (i > 0) prev = max(prev, dp[i - 1][j][k]);
                    if (j > 0) prev = max(prev, dp[i][j - 1][k]);
                    
                    dp[i][j][k] = max(dp[i][j][k], prev + coins[i][j]);

                    if (k < 2 && coins[i][j] < 0) {
                        long long prev_neutral = -1e17;
                        if (i > 0) prev_neutral = max(prev_neutral, dp[i - 1][j][k + 1]);
                        if (j > 0) prev_neutral = max(prev_neutral, dp[i][j - 1][k + 1]);
                        dp[i][j][k] = max(dp[i][j][k], prev_neutral);
                    }
                }
            }
        }
        
        long long ans = dp[m - 1][n - 1][0];
        if (dp[m - 1][n - 1][1] > ans) ans = dp[m - 1][n - 1][1];
        if (dp[m - 1][n - 1][2] > ans) ans = dp[m - 1][n - 1][2];
        
        return (int)ans;
    }
};