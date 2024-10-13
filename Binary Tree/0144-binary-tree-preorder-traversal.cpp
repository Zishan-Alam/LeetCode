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

    vector<int> preorderHelper(TreeNode* root, vector<int> &res){
        //base case
        if(root == nullptr){
            return res;
        }
        //NODE
        res.push_back(root->val);

        //LEFT
        preorderHelper(root->left, res);

        //RIGHT
        preorderHelper(root->right, res);

        return res;

    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        return preorderHelper(root, res);
    }
};
