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

    map<int,int> count;
    int maxi = 0;

    void inorder(TreeNode* root){

        if(!root) return;

        inorder(root->left);

        count[root->val]++;

        if(count[root->val] > maxi){
            maxi = count[root->val];
        }

        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {

        vector<int> modes;

        inorder(root);

        for(auto &it : count){ //counting all values having the maximum frquency
            if(it.second == maxi){
                modes.push_back(it.first);
            }
        }
        return modes;
        
    }
};
