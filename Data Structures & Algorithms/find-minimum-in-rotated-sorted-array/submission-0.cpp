class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int min = nums[0];

        while (l <= r){
            int m = l + (r-l)/2;
            if (nums[m] < min){
                min = nums[m];
            }
            if (nums[l] > nums[m]){
                r = m -1;
            }
            else if (nums[r] < nums[m]){
                l = m + 1;
            }
            else {
                if (nums[l] < min){
                    min = nums[l];
                }
                break;
            }
        }

        return min;
    }
};
