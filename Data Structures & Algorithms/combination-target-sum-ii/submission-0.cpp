class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> current;
        int currentsum = 0;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, res, current, currentsum, target, 0);
        return res;
    }
private:
    void backtrack(vector<int>& candidates, vector<vector<int>>& res, vector<int>& current, int& currentsum, int target, int start){
        if (currentsum == target){
            res.push_back(current);
            return;
        }
        if(currentsum > target){
            return;
        }
        for(int i = start; i<candidates.size(); i++){
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            current.push_back(candidates[i]);
            currentsum += candidates[i];
            backtrack(candidates, res, current, currentsum, target, i+1);
            currentsum -= candidates[i];
            current.pop_back();
        }
    }
};
