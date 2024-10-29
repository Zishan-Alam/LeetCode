// TC : 0(n) where n --> number of bits in number
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;

        while( x!= 0 || y != 0) {
            if( (x & 1) == 1 && (y & 1) == 0 ) count++;
            if( (x & 1) == 0 && (y & 1) == 1 ) count++;

            x >>= 1;
            y >>= 1;
        }
        return count;
    }
};
// TC : 0(1)
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = x ^ y;
        return __builtin_popcount(ans);
    }
};
