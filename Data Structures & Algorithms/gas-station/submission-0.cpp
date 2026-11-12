class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int c = 0;
        int idx = 0;
        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            c += diff;
            if (c < 0) {
                c = 0;
                idx = i + 1;
            }
        }
        return total < 0 ? -1 : idx;
    }
};
