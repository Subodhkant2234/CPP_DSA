class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        for (int position = 0; position < 32; position++) {
            if (n & 1) {
                rev |= 1 << (31 - position);
            }
            n = n >> 1;
        }
        return rev;
    }
};
