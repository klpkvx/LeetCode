class Solution {
public:
    string convert_to_binary (string s){
        int tmp = 0;
        for (int i = 0; i < s.size(); i++)
            tmp = tmp * 10 + (s[i] - '0');

        string result;

        while (tmp > 0){
            result = (tmp % 2 == 0 ? "0" : "1") + result;
            tmp /= 2;
        }
        return result;
    }
    
    string convertDateToBinary(string s) {
        return convert_to_binary(s.substr (0, 4)) + "-" + convert_to_binary(s.substr (5, 2)) + "-" + convert_to_binary(s.substr (8, 2));
    }
};