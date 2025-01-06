class Solution {
public:

    vector<vector<int>> result;

    void solve(int idx, vector<int> &temp, int sum, vector<int> candidates, int target) {
        if(sum == target) {
            result.push_back(temp);
            return;
        }

        if(idx >= candidates.size() || sum > target) return;

        temp.push_back(candidates[idx]);
        solve(idx, temp, sum + candidates[idx], candidates, target);
        temp.pop_back();

        solve(idx+1, temp, sum, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;

        int sum = 0;

        solve(0, temp, sum, candidates, target);

        return result;
    }
};
