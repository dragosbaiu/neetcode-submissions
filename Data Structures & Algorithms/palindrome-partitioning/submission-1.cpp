class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> current;
        bt(s, res, current, 0);
        return res;
    }
private:
    
    void bt(string s, vector<vector<string>> &res, vector<string> &current, int start){
        if (start == s.length()){
            res.push_back(current);
        }
        for (int i = start; i<s.length(); i++){
            if(!(isPalindrome(s, start, i))){continue;}
            current.push_back(s.substr(start, i - start + 1));
            bt(s,res, current,  i + 1);    
            current.pop_back();               
        }
    }
    bool isPalindrome(const string &s, int left, int right){
        while (left <= right){
            if (s[left] == s[right]){
                left++;
                right--;
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
