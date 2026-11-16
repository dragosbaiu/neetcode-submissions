class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> current;
        bt(res, current, n, k, 1);
        return res;
    }

    void bt(vector<vector<int>> &res, vector<int> &current, int n, int k, int start){
        if (current.size() == k){
            res.push_back(current);
            return;
        }
        for (int i = start; i <= n; i++){
            if (std::find(current.begin(), current.end(), i) != current.end()) continue;
            current.push_back(i);
            bt(res, current, n, k, i + 1);
            current.pop_back();
        }
        return;
    }
};