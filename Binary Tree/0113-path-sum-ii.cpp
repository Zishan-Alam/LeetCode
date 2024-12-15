class Solution {
public:

    vector<vector<int> > result;

    void fill(TreeNode* root, int sum, vector<int> temp, int targetSum) {
        if(!root) return;

        sum += root->val;
        temp.push_back(root->val);

        if(!root->left && !root->right) {
            if(sum == targetSum) {
                result.push_back(temp);
            }
        }

        fill(root->left, sum, temp, targetSum);
        fill(root->right, sum, temp, targetSum);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        int sum = 0;

        fill(root, sum, temp, targetSum);

        return result;
    }
};
