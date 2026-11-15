class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        int count = 0;
        for (int i = 0; i<= n; i++){
            int x = i;
            while (x) { x &= x - 1; count++; }
            res.push_back(count);
            count = 0;
        }
        return res;
    }
};
