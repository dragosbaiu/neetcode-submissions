class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = ranges::max(piles);
        int res = r;

        while (l <= r){
            int k = l + (r-l)/2;
            long long hours = 0;

            for (int p: piles){
                hours += ceil(static_cast<double>(p) / k);
            }
            if (hours <= h) {
                res = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return res;
    }
};
