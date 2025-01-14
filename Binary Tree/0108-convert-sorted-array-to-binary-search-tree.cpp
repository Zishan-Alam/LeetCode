class Solution {
public:

    TreeNode* solve(int start, int end, vector<int> & nums) {
        if(start > end) return nullptr;

        int mid = start + (end-start)/2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = solve(start, mid-1, nums);
        root->right = solve(mid+1, end, nums);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return solve(0, n-1, nums);
    }
};
