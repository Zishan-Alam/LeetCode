class Solution {
public:
    int FirstPos(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int res = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                res = mid;
                end = mid - 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return res;
    }

    int LastPos(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int res = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                res = mid;
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int firstPos = FirstPos(nums, target);

        // If target is not found, return [-1, -1]
        if (firstPos == -1) {
            return {-1, -1};
        }

        int lastPos = LastPos(nums, target);
        return {firstPos, lastPos};
    }
};
