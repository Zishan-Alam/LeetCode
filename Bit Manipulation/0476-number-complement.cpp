// TC : 0(logn) where n is the number of bits
// number of bits in a binary representation of a number is proportional to the logarithm of the number.
class Solution {
public:
    int findComplement(int num) {
        if(num == 0) return 1;
        int bitmask = ~0;

        while(num & bitmask) {
            bitmask <<= 1;
        }
        return num ^ ~bitmask;
    }
};
