// TC : 0(n) where n --> number of bits in greater of two numbers
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flips = 0;
        while( start != 0 || goal != 0) {
            if( (start & 1) == 0 && (goal & 1) == 1 ) flips++;
            if( (start & 1) == 1 && (goal & 1) == 0 ) flips++;

            start >>= 1;
            goal >>= 1;
        }
        return flips;
    }
};
// TC : 0(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start ^ goal);
    }
};
