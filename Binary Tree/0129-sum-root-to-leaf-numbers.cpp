class Solution {
public:
    int sumNumbersHelper(TreeNode* root, int currentSum) {
        // Base case: if the node is null, return 0
        if (root == nullptr) {
            return 0;
        }

        // Update the current number (multiply by 10 and add the node's value)
        currentSum = currentSum * 10 + root->val;

        // If it's a leaf node, return the current number
        if (root->left == nullptr && root->right == nullptr) {
            return currentSum;
        }

        // Recursively calculate the sum for the left and right subtrees
        return sumNumbersHelper(root->left, currentSum) + sumNumbersHelper(root->right, currentSum);
    }

    int sumNumbers(TreeNode* root) {
        return sumNumbersHelper(root, 0);  // Start the recursion with an initial sum of 0
    }
};
