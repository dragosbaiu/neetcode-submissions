class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        if (intervals.size() == 0) return 0;

        int cmpy = intervals[0][1];
        int c = 0;
        for (int i = 1; i< intervals.size(); i++){
            if (intervals[i][0]<cmpy){
                c++;
                cmpy = min(cmpy, intervals[i][1]);
            }
            else{
                cmpy = intervals[i][1];
            }
        }
        return c;
    }
};
