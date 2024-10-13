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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Vector to store the result
        vector<vector<int>> res;

        // Return an empty result if the tree is empty
        if (root == nullptr) {
            return res;
        }

        // Queue to store the nodes
        queue<TreeNode*> q;
        q.push(root); // Pushing root to the queue

        while (!q.empty()) {
            int size = q.size();
            vector<int> level; // Store values of each level

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); // Get the front node
                q.pop(); // Remove the node from the queue

                level.push_back(node->val); // Add the node's value to the current level

                // Push the left and right children to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(level); // Add the level to the result
        }
        return res; // Return the result
    }
};
