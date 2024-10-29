class Solution {
public:
    bool isPrime(int n) {
        if(n == 0 || n == 1) return false;

        for(int i=2; i<n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int primeCount = 0;

        for(int i=left; i<=right; i++) {

            int bits = __builtin_popcount(i);
            if( isPrime(bits) ) primeCount++;
        }
        return primeCount;
    }
};
