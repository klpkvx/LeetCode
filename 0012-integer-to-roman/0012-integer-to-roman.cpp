class Solution {
public:
    vector<pair<string, int>> roman_to_int = {
            {"M", 1000},
            {"CM", 900},
            {"D", 500},
            {"CD", 400},
            {"C", 100},
            {"XC", 90},
            {"L", 50},
            {"XL", 40},
            {"X", 10},
            {"IX", 9},
            {"V", 5},
            {"IV", 4},
            {"I", 1}
    };
    string intToRoman(int num) {
        string answer;
        for (auto &[s, value] : roman_to_int) {
            while (num >= value) {
                    num -= value;
                    answer += s;
                }
            }
            return answer;
        }
};