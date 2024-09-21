class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> values;
        unordered_set<string> ops = {"+", "-", "*", "/"};
        for (const string &curr : tokens) {
            if (!ops.contains (curr))
                values.push (curr);
            else {
                int left = stoi (values.top ());
                values.pop ();
                int right = stoi (values.top ());
                values.pop ();
                string result;
                if (curr == "+")
                    result = to_string (right + left);
                else if (curr == "-")
                    result = to_string (right - left);
                else if (curr == "*")
                    result = to_string (right * left);
                else 
                    result = to_string (right / left);
                values.push (std::move (result));
            }
        }
        return values.empty () ?  stoi (tokens[0]) : stoi(values.top ());
    }
};