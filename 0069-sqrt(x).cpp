class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0; // Handle the edge case for 0

        int start = 1;
        int end = x;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            long long square = (long long)mid * mid; // Prevent overflow

            if (square == x) {
                return mid;
            } else if (square > x) {
                end = mid - 1;
            } else {
                ans = mid;
                start = mid + 1;
            }
        }

        return ans;
    }
};
