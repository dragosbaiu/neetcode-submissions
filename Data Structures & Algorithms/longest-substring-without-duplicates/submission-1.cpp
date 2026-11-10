class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int l = 0;
        int r = 0;
        int maxcount = 0;
        int count = 0;
        while (r < s.length()){
            if (map[s[r]] == 0){
                map[s[r]] ++;
                count++;
                r++;
            }
            else{
                map[s[l]] -= 1;
                l++;
                count--;
            }
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
};
