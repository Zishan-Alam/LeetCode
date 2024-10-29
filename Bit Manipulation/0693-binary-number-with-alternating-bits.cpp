//The time complexity is O(log n). This is because the while loop iterates through the bits of the integer `n`, and the number of bits in `n` is proportional to log(n) in base 2.
class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n > 0) {
            int currentBit = n & 1;
            int nextBit = (n>>=1) & 1;

            if(currentBit ^ nextBit != 1) return false;
            n >>= 1;
        }
        return true;
    }
};
