class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int c = 0;
        int max = nums[0];
        for (int num: nums){
            if (c < 0){
                c = 0;
            }
            c += num;
            max = std::max(max, c);
        }
        return max;
    }
};
