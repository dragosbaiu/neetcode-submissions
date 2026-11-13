class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int bestLen = 1;
        int start = 0;
        for (int i = n-1; i>=0; i--){
            for (int j = i; j<n; j++){
                if (s[i]==s[j] && (j - i<= 2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    if (j - i + 1 > bestLen){
                        bestLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, bestLen);
    }
};
