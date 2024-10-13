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

    vector<int> postorderHelper(TreeNode* root, vector<int> &res){
        //base case
        if(root == nullptr){
            return res;
        }
        //Left
        postorderHelper(root->left, res);
        //Right
        postorderHelper(root->right, res);
        //Node
        res.push_back(root->val);

        return res;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        return postorderHelper(root, res);
    }
};
