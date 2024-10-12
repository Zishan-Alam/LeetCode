class Solution {
public:

    int minDepth(TreeNode* root) {
        // Base case: if the tree is empty, the depth is 0
        if (root == NULL) {
            return 0;
        }

        // If left subtree is NULL, recursively find the min depth of the right subtree
        if (root->left == NULL) {
            return minDepth(root->right) + 1;
        }

        // If right subtree is NULL, recursively find the min depth of the left subtree
        if (root->right == NULL) {
            return minDepth(root->left) + 1;
        }

        // If both left and right children exist, return the minimum of both subtrees' depths
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
