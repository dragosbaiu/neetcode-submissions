class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string current;
        backtrack(res, current, n, 0, 0);
        return res;
    }

private:
    void backtrack(vector<string> &res, string &current, int n, int open, int closed){
        if (current.length() == n*2){
            res.push_back(current);
            return;
        }
        if (closed>open){
            return;
        }
        for (char c : {'(', ')'}) {
            if (c == '(' && open == n) continue;
            if (c == ')' && closed == open) continue;
            current.push_back(c);
            if (c == '('){backtrack(res, current, n, open + 1, closed);}
            else {backtrack(res, current, n, open, closed + 1);}
            current.pop_back();
        }
    }
};
