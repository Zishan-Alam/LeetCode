class Solution {
public:

    void solve(TreeNode* root, vector<int> &ans) {
        if(!root) return;

        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
    }

    int minDiffInBST(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);

        int sum = INT_MAX;
        int n = ans.size();
        for(int i=0; i<n-1; i++) {
            int diff = ans[i+1] - ans[i];
            sum = min(sum, diff);
        }
        return sum;
    }
};
