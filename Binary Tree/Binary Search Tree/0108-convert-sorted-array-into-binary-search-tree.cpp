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

    TreeNode* sortedArrayToBSTHelper(vector<int> &nums, int start, int end){
        if(start > end) return nullptr;

        int mid = start + (end-start)/2;

        TreeNode* root = new TreeNode(nums[mid]); //initialize new node with value of mid in nums to ensure height-balanced 
        root->left = sortedArrayToBSTHelper(nums, start, mid-1);
        root->right = sortedArrayToBSTHelper(nums, mid+1, end);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        int start = 0;
        int end  = nums.size() - 1;

        return sortedArrayToBSTHelper(nums, start, end);
        
    }
};
