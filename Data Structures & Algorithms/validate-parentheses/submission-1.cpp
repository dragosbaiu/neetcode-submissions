class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                brackets.push(c);
            } else {
                if (brackets.empty()) return false;
                char t = brackets.top();
                if ((c == ')' && t == '(') ||
                    (c == ']' && t == '[') ||
                    (c == '}' && t == '{')) {
                    brackets.pop();
                } else {
                    return false;
                }
            }
        }
        return brackets.empty();
    }
};