class Solution {
public:
    //s[i * numrows + j]
    // abcdefghi -> 1234 321 23
    string convert(string s, int numrows) {
        if (numrows <= 1)
            return s;
        vector<string> data (numrows, "");
        int idx = 0; // for numrows
        int d = 1;
        for (char c : s) {
            data[idx].push_back (c);
            if (idx == 0)
                d = 1;
            else if (idx == numrows - 1)
                d = -1;
            idx += d;
        }
        return accumulate (data.begin (), data.end (), string{});
    }
};