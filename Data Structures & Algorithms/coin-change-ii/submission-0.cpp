class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(amount + 1, 0));

        for (int i = 0; i <= n; i++) dp[i][0] = 1;   
        for (int i = 1; i <= n; i++) {
            int c = coins[i - 1];                       
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];              
                if (j >= c)
                    dp[i][j] += dp[i][j - c];         
            }
        }
        return (int)dp[n][amount];
    }
};
