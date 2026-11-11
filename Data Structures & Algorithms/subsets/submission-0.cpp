class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> solution;
        vector<int> current;
        backtrack(nums, 0, current, solution);
        return solution;
    }
private:
    void backtrack(vector<int> &nums, int start, vector<int> &current, vector<vector<int>> &solution){
        solution.push_back(current);
        for (int i = start; i < (int)nums.size(); ++i) {
            current.push_back(nums[i]);            
            backtrack(nums, i + 1, current, solution); 
            current.pop_back();                     
        }
    }
};
