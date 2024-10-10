class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0; // Pointer to track elements to keep
        int n = nums.size();

        for (int j = 0; j < n; j++) {
            if (nums[j] != val) {
                nums[i] = nums[j]; // Move non-val element to the front
                i++;  // Increment the pointer for the next position to fill
            }
        }

        return i;  // The new length of the array
    }
};
