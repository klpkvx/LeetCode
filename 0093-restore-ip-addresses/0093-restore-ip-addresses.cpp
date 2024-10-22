class Solution {
public:

    void solve (int dots, int index, string tmp, string &s) {
        if (dots == 4 && index == s.size ()) {
            tmp.erase (tmp.end () - 1);
            answer.push_back (tmp);
            return;
        }
        if (dots > 4 || index >= s.size ()) {
            return;
        }
        int num = 0;
        for (int i = index; i < index + 3; i++) {
            num = num * 10 + s[i] - '0';
            if (num <= 255) {
                tmp += s[i];
                solve (dots + 1, i + 1, tmp + ".", s);
            }
            if (num == 0)
                break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        string tmp;
        solve (0, 0, tmp, s);
        return answer;
    }
private:
    vector<string> answer;
};