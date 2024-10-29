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
