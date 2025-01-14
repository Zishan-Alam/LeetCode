class Solution {
public:

    void findPath(TreeNode* root, int target, int &count, long long currSum) {
        if(!root) return;
      
        currSum += root->val;
        if(currSum == target) count += 1;

        findPath(root->left, target, count, currSum);
        findPath(root->right, target, count, currSum);
    }

    void pathSumEveryNode(TreeNode* root, int target, int &count) {
        if(!root) return;
        int currSum = 0;

        findPath(root, target, count, currSum);

        pathSumEveryNode(root->left, target, count);
        pathSumEveryNode(root->right, target, count);

    }

    int pathSum(TreeNode* root, int target) {
        int count = 0;
        pathSumEveryNode(root, target, count);
        return count;
    }
};
