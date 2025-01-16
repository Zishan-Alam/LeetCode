class Solution {
public:

    void inorder(TreeNode* root, vector<int> &temp) {
        if(!root) return;

        inorder(root->left, temp);
        temp.push_back(root->val);
        inorder(root->right, temp);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> temp;
        inorder(root, temp);

        int n = temp.size();

        int sum;

        for(int i=0; i<n-1; i++) {
            int diff = temp[i+1] - temp[i];
            sum = min(sum, diff);
        }
        return sum;
    }
};
