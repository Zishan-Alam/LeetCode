class Solution {
public:

    TreeNode* prev = nullptr;

    void flatten(TreeNode* root) {
        if(!root) return;

        // Process right subtree first
        flatten(root->right);

        //Process left subtree
        flatten(root->left);

        // Set the current node's right to prev & left to nullptr
        root->right = prev;
        root->left = nullptr;

        // Update prev to current node
        prev = root;
    }
};
