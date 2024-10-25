class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0; // `left` pointer jo non-zero elements ko track karega aur kaha place karna hai, wo decide karega
        
        // Right pointer loop ke saath array ke sabhi elements par chalega
        for(int right = 0; right < nums.size(); right++) {
            if(nums[right] != 0) { // Agar current element zero nahi hai
                swap(nums[right], nums[left]);
                left++; // `left` pointer ko ek position aage badhate hain taaki agle non-zero element ke liye space mile
            }
        }
    }
};
