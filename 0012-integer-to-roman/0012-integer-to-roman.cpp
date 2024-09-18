class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> integer_to_roman = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"},
        };
        string roman_value;
        for (int i = 0; i < integer_to_roman.size (); i++){
            while (num >= integer_to_roman[i].first) {
                roman_value += integer_to_roman[i].second;
                num -= integer_to_roman[i].first;
            }
        }
        return roman_value;
    }
};