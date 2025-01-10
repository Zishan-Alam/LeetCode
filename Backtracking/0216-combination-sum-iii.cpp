class Solution {
public:

    vector<vector<int>> result;

    void solve(int idx, int k, int target, vector<int> &temp) {
        if(temp.size() == k && target == 0) {
            result.push_back(temp);
            return;
        }

        for(int i=idx; i<=9; i++) {

            if(i > target) break;
            temp.push_back(i);
            solve(i+1, k, target-i, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        
        solve(1, k, n, temp);
        return result;
    }
};
