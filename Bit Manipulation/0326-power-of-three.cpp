// TC : 0(logn) - base 3
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        int num = 1;
        while (num < INT_MAX / 3) {
            if (num == n) return true;
            num *= 3;
        }
        if(num == n) return true;
        return false;
    }
};

// TC : 0(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        for(int i=0;i<100;i++){
            if(pow(3,i) == n) return true;
        }
        return false;
    }
};
