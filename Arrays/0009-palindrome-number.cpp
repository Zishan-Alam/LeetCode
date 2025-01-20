class Solution {
public:
    long long int rev(int x) {
        long long int rev = 0;
        while(x != 0) {
            int digit = x % 10;
            rev = (rev * 10) + digit;
            x /= 10;
        }
        return rev;
    }

    bool isPalindrome(int x) {
        if(x < 0) return false;

        long long int reverse = rev(x);

        if(x == reverse) return true;
        return false;
    }
};
