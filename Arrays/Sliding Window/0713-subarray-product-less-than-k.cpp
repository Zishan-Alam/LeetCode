class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        if(k <= 1) return 0;

        int i = 0;
        int j = 0;

        int prod = 1;

        while(j < n) {
            prod *= nums[j];

            if(prod >= k) {
                prod /= nums[i];
                i++;
            }

            count += j-i+1;
            j++;
        }
        return count;
    }
};
