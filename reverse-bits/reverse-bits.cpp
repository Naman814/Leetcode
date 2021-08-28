class Solution {
public:
    uint32_t reverseBits(uint32_t A) {
        
    unsigned int num = 0;
    int bits = 31;
    int i = 0;
    while (A)
    {
        num = num + pow(2, 31 - i) * (A % 2);
        A = A / 2;
        i++;
    }
    return num;
    }
};