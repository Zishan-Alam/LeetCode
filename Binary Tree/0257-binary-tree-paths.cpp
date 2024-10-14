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

    vector<string> binaryTreePathsHelper(TreeNode* root, string path, vector<string> &result){
        if(!root) return result;

        path = path + to_string(root->val);

        // If it's a leaf node, add the path to the result
        if(!root->left && !root->right){
            result.push_back(path);
        }
        else{
            // Otherwise, continue building the path
            path = path + "->";
            binaryTreePathsHelper(root->left, path, result);
            binaryTreePathsHelper(root->right, path, result);

        }
        return result;
    }
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> result;
        return binaryTreePathsHelper(root, "", result);  // Start with an empty path
        
    }
};
