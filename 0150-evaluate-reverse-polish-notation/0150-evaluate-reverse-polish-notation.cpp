class Solution {
public:
    unordered_map<string, function<int (int, int)>> ops = {
        {"+", [] (int a, int b) {return a + b; }},
        {"-", [] (int a, int b) {return a - b; }},
        {"*", [] (int a, int b) {return a * b; }},
        {"/", [] (int a, int b) {return a / b; }}
    };
    int evalRPN(vector<string>& tokens) {
        stack<int> values;
        for (const string &t : tokens) {
            if (!ops.contains (t)) {
                values.push (stoi (t));
            } else {
                int right = values.top (); values.pop ();
                int left = values.top (); values.pop ();
                values.push (ops[t] (left, right));
            }
        }
        return values.top ();
    }  
};