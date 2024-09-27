class Solution {
public:

    int binSearch(vector<int> &nums, int start, int end, int target){

        while(start<=end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
    }

    int findMin(vector<int> &nums){
        int start = 0;
        int end = nums.size() - 1;
        int n = nums.size();

        while(start <= end){

            if(nums[start] < nums[end]){
                return start;
            }

            int mid = start + (end-start)/2;

            if( (mid == 0 || nums[mid] < nums[mid-1]) && (mid == n - 1 || nums[mid] < nums[mid+1]) ){
                return mid;
            }
            //sorted part
            else if(nums[mid] >= nums[start]){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int minEle = findMin(nums);

        int start = 0;
        int end = nums.size() - 1;

        //binary search ka answers
        int first = binSearch(nums, start, minEle - 1, target);
        int second = binSearch(nums, minEle, end, target);

        if(first == -1 && second == -1){
            return -1;
        }
        else if(first != -1){
            return first;
        }
        else{
            return second;
        }
    }
};
