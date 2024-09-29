class Solution {
public:

// IX
// 
    int romanToInt(string s) {
        unordered_map<char, int> roman_to_i = { 
            {'I', 1}, 
            {'V', 5}, 
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
         };
         int answer = 0;
         for (int i = 0; i < s.size (); i++) {
            if (i + 1 < s.size () && roman_to_i[s[i]] < roman_to_i[s[i + 1]])
                answer -= roman_to_i[s[i]];
            else
                answer += roman_to_i[s[i]];
         }
         return answer;
    }
};