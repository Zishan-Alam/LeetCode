class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int n = nums.size();
        int end = n - 1;

        while (start <= end) {
            // If the array is already sorted, return the first element
            if (nums[start] <= nums[end]) {
                return nums[start];
            }

            int mid = start + (end - start) / 2;

            // Check if the mid element is the minimum element
            if ((mid == 0 || nums[mid] < nums[mid - 1]) && (mid == n - 1 || nums[mid] < nums[mid + 1])) {
                return nums[mid];
            }

            // Decide which half to search in
            if (nums[mid] >= nums[start]) {
                // If left part is sorted, search in the right part
                start = mid + 1;
            } else {
                // If right part is unsorted, search in the left part
                end = mid - 1;
            }
        }

        return -1; // This case should not be reached if input is valid
    }
};
