class Solution {
public:
    int minSwaps(string s) {
        int st = 0;
        int err = 0;
        for (char c : s) {
            if (c == '[')
                st++;
            else if (c == ']') {
                if (st > 0)
                    st--;
            }
        }
        return (st + 1) / 2;  
    }
};