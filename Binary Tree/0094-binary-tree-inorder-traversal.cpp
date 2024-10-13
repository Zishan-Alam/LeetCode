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
    vector<int> inorderTraversal(TreeNode* root) {
        //base case
        vector<int> res;
        if(root == NULL){
            return res;
        }

        //LEFT
        inorderTraversal(root->left);

        //NODE
        res.push_back(root->val);

        //RIGHT
        inorderTraversal(root->right);

        return res;
    }
};
