class Solution {
public:

    void solve(int maxi, int mini, TreeNode* root, int &ans) {
        if(!root) {
            ans = max(ans, maxi-mini);
            return;
        }

        maxi = max(maxi, root->val);
        mini = min(mini, root->val);

        solve(maxi, mini, root->left, ans);
        solve(maxi, mini, root->right, ans);
    }

    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;

        int maxi = root->val;
        int mini = root->val;

        int ans = 0;
        solve(maxi, mini, root, ans);
        return ans;
    }
};
