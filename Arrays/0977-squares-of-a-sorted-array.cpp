class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int prod = nums[i]*nums[i];
            nums[i] = prod;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};
