class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> values;
        int answer = 0;
        unordered_map<string, function<double (int, int)>> commands = {
            {"+", [] (int a, int b) {return a + b;} },
            {"*", [] (int a, int b) {return a * b;} },
            {"-", [] (int a, int b) {return a - b;} },
            {"/", [] (int a, int b) {return a / b;} },
        };
        for (int i = 0; i < tokens.size (); i++) {
            const string &curr = tokens[i];
            if (!commands.contains (curr)) {
                values.push (stoi (curr));
            } else {
                int right = values.top ();
                values.pop ();
                int left = values.top ();
                values.pop ();
                values.push (commands[curr] (left, right));
            }
        }
        return values.empty () ? 0 : values.top ();
    }
};