class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string tmp;
        solve (0, 0, s, tmp);
        return answer;
    }
private:
    void solve (int dots, int index, string &s, string tmp) {

        if (index == s.size () && dots == 4) {
            tmp.erase (tmp.end () - 1);
            answer.push_back (tmp);
            return;
        }

        if (s.size () - index > (4 - dots) * 3)
            return;

    //    if (s.size () - index < 4 - dots)
    //        return;

        int num = 0;
        for (int i = index; i < index + 3; i++) {
            num = num * 10 + (s[i] - '0');
            if (num <= 255) {
                tmp += s[i];
                solve (dots + 1, i + 1, s, tmp + '.');
            }
            if (num == 0)
                break;
        }
    }
private:
    vector<string> answer;
};