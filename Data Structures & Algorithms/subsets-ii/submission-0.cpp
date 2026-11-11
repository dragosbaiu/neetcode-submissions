class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        int start = 0;
        sort(nums.begin(), nums.end());
        backtrack(nums, res, current, start);
        return res;
    }
private:
     void backtrack(vector<int> &nums, vector<vector<int>> &res, vector<int> &current, int start){
        res.push_back(current);

        for(int i = start; i<nums.size(); i++){
            if (i > start && nums[i] == nums[i-1]){continue;}
            current.push_back(nums[i]);
            backtrack(nums, res, current, i+1);
            current.pop_back();
        }
    }
};
