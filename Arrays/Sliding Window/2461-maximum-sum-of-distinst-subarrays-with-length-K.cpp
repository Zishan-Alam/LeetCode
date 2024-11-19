// TC : O(n) where n is the number of elements in the input vector
// SC : O(k) where k is the size of the current window
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0;
        int j = 0;

        long long int result = 0;
        long long int sum = 0;

        unordered_set<int> set;

        while(j < n) {
            //check whether nums[j] is present in the current window
            while(set.count(nums[j])) {
                sum -= nums[i];
                set.erase(nums[i]);
                i++;
            }

            sum += nums[j];
            set.insert(nums[j]);

            if(j-i+1 == k) {
                result = max(result, sum);
                sum -= nums[i];
                set.erase(nums[i]);
                i++;
            }
            j++;
        }
        return result;
    }
};
