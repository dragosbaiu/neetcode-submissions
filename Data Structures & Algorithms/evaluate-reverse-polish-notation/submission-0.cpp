class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for (const string& token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                numbers.push(stoi(token));
            } else {
                int b = numbers.top(); numbers.pop();   
                int a = numbers.top(); numbers.pop();  
                if (token == "+")      numbers.push(a + b);
                else if (token == "-") numbers.push(a - b);
                else if (token == "*") numbers.push(a * b);
                else                   numbers.push(a / b);
            }
        }
        return numbers.top();
    }
};