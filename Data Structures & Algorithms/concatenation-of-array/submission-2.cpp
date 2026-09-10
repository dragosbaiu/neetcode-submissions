class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        ans.reserve(2 * n);
        // copy(ans.start() , ans.end() , nums.start());
        // copy(ans.start() , ans.end() , nums.start());


        
        for(int j=0;j<2;j++) for(int i=0;i<n;i++){
            ans.push_back(nums.at(i));
        }


        return ans;
    }
};