class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i=0;     //always point to the unique element
        int j=1;     //will iterate through the array

        while(j < n) {
            if(nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i+1;    //total number of unique elements
    }
};
