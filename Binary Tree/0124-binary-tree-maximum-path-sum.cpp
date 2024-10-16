/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int maxPathSumHelper(TreeNode* root, int &res){

        //base case
        if(!root) return 0;

        //hypothesis
        int leftAns = maxPathSumHelper(root->left, res);
        int rightAns = maxPathSumHelper(root->right, res);

        //induction
        int temp = max(max(leftAns, rightAns) + root->val, root->val);
        int ans = max(leftAns + rightAns + root->val, temp);
        
        res = max(res, ans);
        return temp;

    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSumHelper(root, res);

        return res;
        
    }
};
