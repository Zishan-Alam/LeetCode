class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        //counting the occurences of 0s, 1s, 2s
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) count0++;
            else if(nums[i] == 1) count1++;
            else count2++;
        }
        //replacing the values of each
        for(int i=0; i<nums.size(); i++){
            if(i<count0) nums[i] = 0;
            else if(i<(count0+count1)) nums[i] = 1;
            else nums[i] = 2;
        }
        return;
    }
};

//.........................................................DUTCH NATIONAL FLAG ALGORITHM............................................................................//

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;

        while(mid<=high){
            if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
            else if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else{
                mid++;
            }
        }
        return;
    }
};
