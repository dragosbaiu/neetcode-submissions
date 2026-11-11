class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits == "") return res;
        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string current;
        bt(digits, current, res, letters, 0);
        return res;
    }
    void bt(string digits, string &current, vector<string> &res,vector<string> letters, int pos){
        if (pos == digits.length()){
            res.push_back(current);
            return;
        }
        string options = letters[digits[pos] - '0'];
        for (char c : options){
            current.push_back(c);                      
            bt(digits, current, res, letters, pos + 1);  
            current.pop_back(); 
        }
    }
};
