//......................................................................PREFIX SUM APPROACH.........................................................................//
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        //calculating the totalSum
        for(int i=0; i<n; i++) totalSum += nums[i];

        //creating the prefix sum array
        vector<int> prefixSum(n+1);
        prefixSum[0] = 0;
        for(int i=1; i<n; i++) prefixSum[i] = prefixSum[i-1] + nums[i-1];

        for(int i=0; i<n; i++){
            int leftSum = prefixSum[i];
            int rightSum = totalSum - leftSum - nums[i];
            if(leftSum == rightSum) return i;
        }
        return -1;
    }
};

//.......................................................................NO EXTRA SPACE.............................................................................//

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        int cumulativeSum = 0;

        //calculating the totalSum
        for(int i=0; i<n; i++) totalSum += nums[i];

        for(int i=0; i<n; i++){

            int leftSum = cumulativeSum; //cumulativeSum is the sum of elements prior to index
            int rightSum = totalSum - cumulativeSum - nums[i];
            if(leftSum == rightSum) return i;

            cumulativeSum += nums[i];   //adding the value to cumulativeSum for next iteration

        }
        return -1;
    }
};
