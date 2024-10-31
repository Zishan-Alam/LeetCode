// Sorting
// TC : O(nlogn)
// SC : O(1)
class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return (n < 3)? -1 : nums[1];
    }
};

// TC : O(n)
// SC : O(1)
class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n = nums.size();

        if(n < 3) return -1;

        int max = INT_MIN;
        int min = INT_MAX;

        for(int i=0; i<n; i++) {
            if(nums[i] < min)  min = nums[i];
            if(nums[i] > max)  max = nums[i];
        }

        for(int i=0; i<n; i++) {
            if(nums[i] != min && nums[i] != max) return nums[i];
        }
        return -1;
    }
};
