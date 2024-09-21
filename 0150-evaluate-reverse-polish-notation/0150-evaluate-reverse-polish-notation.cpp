class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> values;
        unordered_map<string, function<int (int, int)>> ops = {
            {"+", [] (int a, int b) { return (a + b); }},
            {"-", [] (int a, int b) { return (a - b); }},
            {"*", [] (int a, int b) { return (a * b); }},
            {"/", [] (int a, int b) { return (a / b); }},
        };
        for (const string &curr : tokens) {
            if (!ops.contains (curr))
                values.push (stoi (curr));
            else {
                int left = values.top ();
                values.pop ();
                int right = values.top ();
                values.pop ();
                values.push(ops[curr](right, left));
            }
        }
        return values.top ();
    }
};