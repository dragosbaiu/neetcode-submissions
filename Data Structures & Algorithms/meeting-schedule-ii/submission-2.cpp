/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(const Interval &a, const Interval &b){
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {

        if (intervals.size()==0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> ends;

        for (const Interval& iv: intervals){
            if (!ends.empty() && ends.top() <= iv.start){
                ends.pop();
            }
            ends.push(iv.end);
        }
        
        return ends.size();
    }
};
