class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        vector<int> res(len2 + 1, 0);

        for (int i = 1; i <= len1; i++) {
            int diag = 0;                   
            for (int j = 1; j <= len2; j++) {
                int above = res[j];     
                if (text1[i - 1] == text2[j - 1])
                    res[j] = diag + 1;    
                else
                    res[j] = max(res[j], res[j - 1]); 
                diag = above;        
            }
        }
        return res[len2];
    }
};
