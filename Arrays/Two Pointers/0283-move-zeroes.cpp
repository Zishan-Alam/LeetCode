class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;

        //0 to j-1 --> non-zero
        //j to i-1 --> zero
        //i to end --> unknown

        while(i < nums.size()) {
            if(nums[i] == 0) i++;
            else{
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
    }
};
