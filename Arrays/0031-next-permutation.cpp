class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //Step-01: find the pivot index
        int n = nums.size();
        int idx = -1;

        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }
        if(idx == -1){ //all the elements are sorted 
            reverse(nums.begin(), nums.end());
            return;
        }
        //Step-02: reversing/sorting the next part
        reverse(nums.begin() + idx + 1, nums.end());

        //Step-03: finding the element greater then idx
        int greaterPivot;
        for(int i=idx+1; i<n; i++){
            if(nums[i] > nums[idx]){
                greaterPivot = i;
                break;
            }

        }
        //Step-04: swapping the pivot with element(greater than pivot).
        swap(nums[idx], nums[greaterPivot]);
    }
};
