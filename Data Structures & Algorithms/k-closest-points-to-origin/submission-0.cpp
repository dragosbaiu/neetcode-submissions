class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> h;
        for (int i = 0; i< points.size(); i++){
            int d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            h.push({d, i});
            if (h.size()>k){
                h.pop();
            }
        }
        
        vector<vector<int>> res;
        while (!h.empty()) {
            res.push_back(points[h.top().second]); 
            h.pop();
        }
        return res;
    }
};
