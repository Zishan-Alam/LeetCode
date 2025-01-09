class Solution {
public:
    vector<vector<int>> result; // To store all unique subsets
    int n;

    void solve(int idx, vector<int> &temp, vector<int> &nums) {
        // Add the current subset to the result
        result.push_back(temp);

        for (int i = idx; i < n; i++) {
            // Skip duplicates
            if (i > idx && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]); // Include current element
            solve(i + 1, temp, nums); // Move to the next index
            temp.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp; // Temporary vector to store subsets
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        n = nums.size();

        solve(0, temp, nums); // Start recursion from index 0
        return result;
    }
};
