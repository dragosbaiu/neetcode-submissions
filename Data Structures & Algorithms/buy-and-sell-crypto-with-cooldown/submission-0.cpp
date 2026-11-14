class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;

        int held = -prices[0], sold = 0, rest = 0;
        for (int i = 1; i < n; i++) {
            int prevHeld = held, prevSold = sold, prevRest = rest;
            held = max(prevHeld, prevRest - prices[i]);
            sold = prevHeld + prices[i];
            rest = max(prevRest, prevSold);
        }
        return max(sold, rest);
    }
};