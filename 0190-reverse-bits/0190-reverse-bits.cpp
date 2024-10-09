class Solution {
public:
// 1101 - 8 + 4 + 1 = 13
// 1011 - 8 + 2 + 1 = 11
    uint32_t reverseBits(uint32_t n) {
        uint32_t value = 0;
        int shift = 31;
        while (n > 0) {
            value ^= (n % 2) << shift;
            shift--;
            n = n >> 1;
        }
        return value;
    }
};