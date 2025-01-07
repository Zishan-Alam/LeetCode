class Solution {
public:

    vector<vector<int>> result;
    int n;

    void solve(int idx, vector<int> &temp, vector<int>& candidates, int target) {

        if(target < 0) return;
        
        if(target == 0) {
            result.push_back(temp);
            return;
        }

        for(int i=idx; i<n; i++) {

            if(i > idx && candidates[i] == candidates[i-1]) continue;

            temp.push_back(candidates[i]);
            solve(i+1, temp, candidates, target - candidates[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        solve(0, temp, candidates, target);
        return result;
    }
};
