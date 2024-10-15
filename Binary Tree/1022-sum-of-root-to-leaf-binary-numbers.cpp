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

    int sumRootToLeafHelper(TreeNode* root, int currentSum) {
        // Base case: if the node is null, return 0
        if(!root) return 0;

        // Update the current sum by shifting the binary sum left and adding the node's value
        currentSum = (currentSum << 1) | root->val;

        // If it's a leaf node, return the current sum
        if(!root->left && !root->right) {
            return currentSum;
        }

        // Recur for the left and right children
        int leftSum = sumRootToLeafHelper(root->left, currentSum);
        int rightSum = sumRootToLeafHelper(root->right, currentSum);

        // Return the total sum from both subtrees
        return leftSum + rightSum;

    }
    int sumRootToLeaf(TreeNode* root) {
        
        return sumRootToLeafHelper(root, 0);
        
    }
};
