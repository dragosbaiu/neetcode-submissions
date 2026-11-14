class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> res(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 0; i <= len1; i++) res[i][0] = i;   
        for (int j = 0; j <= len2; j++) res[0][j] = j;
        for (int i = 1; i<=len1; i++){
            for (int j = 1; j <=len2; j++){
                if (word1[i-1]==word2[j-1]){
                    res[i][j] = res[i-1][j-1];
                }
                else{
                    res[i][j] = 1 + std::min({res[i-1][j-1], res[i-1][j], res[i][j-1]});
                }
            }
        }
        return res[len1][len2];
    }
};
