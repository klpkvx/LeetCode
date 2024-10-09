class Solution {
public:
// 1101 - 8 + 4 + 1 = 13
// 1011 - 8 + 2 + 1 = 11
    uint32_t reverseBits(uint32_t n) {
        uint32_t value = 0;
        int shift = 31;
        for (int i = 0; i < 32; i++) {
            value = value << 1;
            value |= (n & 1);
            n = n >> 1;
        }
        return value;
    }
};