class Solution {
public:
    bool isPowerOfTwo(int n) {
        int bits = __builtin_popcount(n);
        //if number is negative or 0 
        if(n <= 0) return false;
        //number of bits in even number is 1 or 0
        if(bits == 1) return true;
        return false;
    }
};

// Another approach
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return ( n>0 && (n&(n-1))==0) ? true : false;
    }
};
