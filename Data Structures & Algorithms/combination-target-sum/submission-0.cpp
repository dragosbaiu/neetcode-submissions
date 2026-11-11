class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> current;
        int currentsum = 0;
        backtrack(nums, res, current, target, currentsum, 0);
        return res;
    }
private:
    void backtrack (vector<int> &nums, vector<vector<int>> &res, vector<int> &current, int target, int &currentsum, int start){
        if (currentsum == target){
            res.push_back(current);
            return;
        }
        if (currentsum > target) return;
        for (int i = start; i<nums.size(); i++){
            current.push_back(nums[i]);
            currentsum += nums[i];
            backtrack(nums, res, current, target, currentsum, i);
            current.pop_back();
            currentsum -= nums[i];
        }
    }
};
