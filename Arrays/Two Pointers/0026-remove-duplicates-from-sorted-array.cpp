class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        int k=0; //iterator for unique index
        int i=0; //iterator to compare num[i] and num[j]
        int j=1; //iterator to check unique elements

        while(j<n){
            if(nums[i] == nums[j]){
                j++; //elements are same
            }
            else if(nums[i] != nums[j]){
                nums[k+1] = nums[j]; //next unique index mai put karo
                i=j; 
                j++;
                k++;
            }
        }
        return k+1;
    }
};
