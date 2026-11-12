class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int l = 0, r = 0;

        while(r < nums.size()-1){
            int max = 0;
            for (int i = l; i < r+1; i++){
                max = std::max(max, i + nums[i]);
            }
            l = r + 1;
            r = max;
            res += 1;
        }
        return res;
    }
};
