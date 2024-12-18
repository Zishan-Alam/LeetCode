class Solution {
public:

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
        if (start > end) return nullptr;

        int rootVal = preorder[idx]; // Take the current root value from preorder
        idx++; // Move to the next index in preorder

        TreeNode* root = new TreeNode(rootVal);

        // Find the index of rootVal in inorder
        int i = start;
        for (; i <= end; i++) {
            if (inorder[i] == rootVal) break;
        }

        // Recursively build the left and right subtrees
        root->left = solve(preorder, inorder, start, i - 1, idx);
        root->right = solve(preorder, inorder, i + 1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0; // Start index for preorder
        return solve(preorder, inorder, 0, preorder.size() - 1, idx);
    }
};
