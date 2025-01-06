//- Time Complexity: O(n * 2^n)
//- Space Complexity: O(n * 2^n)
class Solution {
public:

    vector<vector<int>> result;

    void solve(int idx, vector<int> &temp, vector<int> &nums) {
        if(idx >= nums.size()) {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(idx+1, temp, nums);
        temp.pop_back();
        solve(idx+1, temp, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(0, temp, nums);
        return result;
    }
};
