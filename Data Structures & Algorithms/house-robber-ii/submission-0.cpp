class Solution {
public:
    int robLine(vector<int>& nums, int lo, int hi){
        int prev2 = 0, prev1 = 0, prev0 = 0;
        for (int i = lo; i<=hi; i++){
            int current = nums[i] + std::max(prev1, prev2);
            prev2 = prev1;
            prev1 = prev0;
            prev0 = current;
        }
        return std::max(prev0, prev1);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robLine(nums, 0, n - 2), robLine(nums, 1, n - 1));
    }
};
