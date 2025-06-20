class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (string token: tokens) {
            if (token == "+") {
                int f = stk.top(); stk.pop();
                int s = stk.top(); stk.pop();
                int r = f + s;
                stk.push(r);
            } else if (token == "-") {
                int f = stk.top(); stk.pop();
                int s = stk.top(); stk.pop();
                int r = s - f;
                stk.push(r);
            } else if (token == "*") {
                int f = stk.top(); stk.pop();
                int s = stk.top(); stk.pop();
                int r = f * s;
                stk.push(r);
            } else if (token == "/") {
                int f = stk.top(); stk.pop();
                int s = stk.top(); stk.pop();
                int r = s / f;
                stk.push(r);
            } else {
                int t = stoi(token);
                stk.push(t);
            }
        }

        int res = stk.top();
        return res;
    }
};