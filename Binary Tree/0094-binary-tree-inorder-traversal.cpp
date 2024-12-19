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
