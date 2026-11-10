class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map <char, int> m1;
        unordered_map <char, int> m2;
        int l = 0;
        int r = 0;
        for (int i = 0; i< s1.length(); i++){
            m1[s1[i]] ++;
            m2[s2[i]] ++;
            r++;
        }   
        if (m1 == m2){
            return true;
        }
        else{
            while (r < s2.length()){
                m2[s2[l]] --;
                if (m2[s2[l]] == 0) m2.erase(s2[l]);
                l++;
                m2[s2[r]] ++;
                r++;
                if (m1 == m2){
                    return true;
                }
            }
        }
        return false;
    }
};
