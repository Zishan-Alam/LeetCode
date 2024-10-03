class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(nums[nums[0]] != nums[0]){
            swap(nums[nums[0]], nums[0]);
        }
        return nums[0];
    }
};
