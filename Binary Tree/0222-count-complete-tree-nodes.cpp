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

    int height(TreeNode* root){
        int height = 0;

        while(root != nullptr){
            root = root->left;
            height++;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0; 

        int left = height(root->left);
        int right = height(root->right);

        if(left == right){
            return (1 << left) + countNodes(root->right); //2^left + rightValaPart (-1 + 1) //formula+root
        } 
        else {
            return (1 << right) + countNodes(root->left); //2^right + leftValaPart (-1+1) //formula+root
        }
    }
};
