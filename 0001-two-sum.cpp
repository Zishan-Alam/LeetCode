class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> numWithIndex(n);
        
        // Step 1: Store the numbers along with their original indices
        for (int i = 0; i < n; i++) {
            numWithIndex[i] = {nums[i], i};
        }

        // Step 2: Sort the array based on the values (not the indices)
        sort(numWithIndex.begin(), numWithIndex.end());

        // Step 3: Use two-pointer approach
        int i = 0;
        int j = n - 1;
        
        while (i < j) {
            int sum = numWithIndex[i].first + numWithIndex[j].first;
            
            if (sum == target) {
                // Return the original indices of the two numbers
                return {numWithIndex[i].second, numWithIndex[j].second};
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        
        // If no solution is found, return {-1, -1}
        return {-1, -1};
    }
};
