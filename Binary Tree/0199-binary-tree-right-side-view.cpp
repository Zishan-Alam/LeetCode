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

    vector<int> rightsideHelper(TreeNode* root, int level, vector<int> &nums){

        //base case
        if(root == nullptr){
            return nums;
        }

        if(level == nums.size()){
            nums.push_back(root->val);
        }

        rightsideHelper(root->right, level+1, nums);   //right to iterate the right side first
        rightsideHelper(root->left, level+1, nums);

        return nums;

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> nums;
        return rightsideHelper(root, 0, nums);
        
    }
};
