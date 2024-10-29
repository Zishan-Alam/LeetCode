// TC : 0(logn) - base 4
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        int num = 1;
        while(num < INT_MAX/4) {
            if(num == n) return true;
            num = num*4;
            
        }
        if(num == n) return true;
        return false;
    }
};

// TC : 0(1)
class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int i=0;i<100;i++){
            if(pow(4,i) == n) return true;
        }
        return false;
    }
};
