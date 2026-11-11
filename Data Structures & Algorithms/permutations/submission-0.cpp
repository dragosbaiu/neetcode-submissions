class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        int numssize = nums.size();
        vector<bool> used(numssize + 1);
        backtrack(nums, res, current, used, numssize);
        return res;
    }
private:
    void backtrack(vector<int> &nums, vector<vector<int>> &res, vector<int> &current, vector<bool> &used, int numssize){
        if(current.size() == numssize){
            res.push_back(current);
            return;
        }
        for (int i = 0; i<numssize; i++){
            if(used[i]){
                continue;
            }
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, res, current, used, numssize);
            current.pop_back();
            used[i] = false;
        }
    }
};
