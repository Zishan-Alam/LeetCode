/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: if the current node is null, return false
        if (root == nullptr) {
            return false;
        }

        // Check if we are at a leaf node and the remaining targetSum equals the
        // node's value
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }

        // Recursively check the left and right subtrees, updating the targetSum
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};
