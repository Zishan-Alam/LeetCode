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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // Base cases:
        // If both nodes are null, return null
        if (root1 == NULL && root2 == NULL) {
            return NULL;
        }

        // If one of the nodes is null, return the other node
        if (root1 == NULL) {
            return root2;
        }
        if (root2 == NULL) {
            return root1;
        }

        // Create a new node with the sum of the values from both trees
        TreeNode* root = new TreeNode(root1->val + root2->val);

        // Recursively merge the left and right subtrees
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);

        // Return the merged tree rooted at the new node root
        return root;
    }
};
