class Solution {
public:
    vector<pair<string, int>> int_to_rom = {
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
        for (int i = 0; i < int_to_rom.size(); i++) {
            while (num >= int_to_rom[i].second) {
                num -= int_to_rom[i].second;
                answer += int_to_rom[i].first;
            }
        }
        return answer;
    }
};