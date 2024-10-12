class Solution {
public:
    // Helper function to calculate the height and check if the tree is balanced
    int checkHeight(TreeNode* root) {
        // Base case: if the node is null, return 0 as height
        if (root == NULL) {
            return 0;
        }

        // Recursively calculate the height of the left and right subtrees
        int leftHeight = checkHeight(root->left);
        int rightHeight = checkHeight(root->right);

        // If any subtree is unbalanced, propagate -1 upwards
        if (leftHeight == -1 || rightHeight == -1) {
            return -1;
        }

        // If the current node is unbalanced, return -1
        if (abs(leftHeight - rightHeight) > 1) { // Corrected this condition
            return -1;
        }

        // Return the height of the current subtree
        return max(leftHeight, rightHeight) + 1;
    }

    // Main function to check if the tree is balanced
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
