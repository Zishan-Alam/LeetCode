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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //base case
        if(p == NULL && q == NULL){
            return true;
        }
        //if one tree is null while other is not
        if(p != NULL && q == NULL){
            return false;
        }
        //if one tree is null while other is not
        if(p == NULL && q != NULL){
            return false;
        }
        //if values of both are different
        if(p->val != q->val){
            return false;
        }

        //recursive call for left and right
        bool ans = isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return ans;
        
    }
};
