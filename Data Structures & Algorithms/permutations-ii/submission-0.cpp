class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> current;
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<vector<int>> res;
        int numSize = nums.size();
        bt(res, current, used, nums);
        return res;
    }
    void bt(vector<vector<int>> &res, vector<int> &current, vector<bool> &used, vector<int> &nums){
        if (current.size() == nums.size()){
            res.push_back(current);
            return;
        }
        for (int i = 0; i<nums.size(); i++){
            if (used[i] == true) continue;
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            used[i] = true;
            current.push_back(nums[i]);
            bt(res, current, used, nums);
            current.pop_back();
            used[i] = false;
        }
    }
};