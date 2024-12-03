class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            // If mid element is greater than the next element, peak is on the
            // left side (including mid)
            if (nums[mid] > nums[mid + 1]) {
                end = mid;
            }
            // If mid element is less than the next element, peak is on the
            // right side
            else {
                start = mid+1;
            }
        }

        // Return the index of the peak element
        return start;
    }
};
