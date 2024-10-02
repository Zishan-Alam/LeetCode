class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int a = 0;
        long long int b = sqrt(c); // Start b at the square root of c

        // Two-pointer approach
        while (a <= b) {
            long long int sum = a * a + b * b;

            if (sum == c) {
                return true; // Found a valid pair (a, b)
            } else if (sum > c) {
                b--; // Decrease b to reduce the sum
            } else {
                a++; // Increase a to increase the sum
            }
        }

        return false; // No valid pairs found
    }
};
