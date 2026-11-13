class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> mx(n), mn(n);
        mx[0] = nums[0];
        mn[0] = nums[0];
        int best = nums[0];

        for (int i = 1; i< n; i++){
            int x = nums[i];
            mx[i] = std::max({x, x * mx[i - 1], x * mn[i - 1]});
            mn[i] = std::min({x, x * mx[i - 1], x * mn[i - 1]});
            best = std::max(mx[i], best);
        }
        return best;
    }
};
