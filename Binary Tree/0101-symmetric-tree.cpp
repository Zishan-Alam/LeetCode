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
    // Helper function to compare two subtrees, 
    //this function takes two nodes and checks 
    //if they are mirrors of each other.
    bool isMirror(TreeNode* left, TreeNode* right) {
        // If both nodes are null, they are symmetric (mirrored)
        if (left == NULL && right == NULL) {
            return true;
        }
        
        // If only one of the nodes is null, they are not symmetric
        if (left == NULL || right == NULL) {
            return false;
        }
        
        // The values of the nodes must be the same, and the left and right subtrees
        // must be mirrors of each other
        return (left->val == right->val) && 
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        // A null tree is symmetric
        if (root == NULL) {
            return true;
        }
        
        // Use the helper function to compare the left and right subtrees
        return isMirror(root->left, root->right);
    }
};
