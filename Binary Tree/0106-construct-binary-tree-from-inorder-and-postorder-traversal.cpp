//time complexity of the provided solution for constructing a binary tree from inorder and postorder traversals is O(n^2) in the worst case.
//space complexity is O(n) due to the recursive call stack.
class Solution {
public:

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
        if(inStart > inEnd || postStart > postEnd) return nullptr;

        int rootVal = postorder[postEnd];
        int i = inStart;

        for(; i <= inEnd; i++) {
            if(rootVal == inorder[i]) break;
        }

        int leftSize  = i - inStart;
        int rightSize = inEnd - i;

        TreeNode* root = new TreeNode(rootVal);
        root->left  = solve(inorder, postorder, inStart, i-1, postStart, postStart + leftSize - 1);
        root->right = solve(inorder, postorder, i+1, inEnd, postEnd - rightSize, postEnd - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();

        int inStart = 0;
        int inEnd = n-1;

        int postStart = 0;
        int postEnd = n-1;

        return solve(inorder, postorder, inStart, inEnd, postStart, postEnd);
    }
};

//TC : O(n)
//SC : O(n)
class Solution {
public:

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int ,int> &mp) {
        if(inStart > inEnd && postStart > postEnd) return nullptr;

        int rootVal = postorder[postEnd];
        int inIdx = mp[rootVal];

        int leftSize  = inIdx - inStart;
        int rightSize = inEnd - inIdx;

        TreeNode* root = new TreeNode(rootVal);
        root->left  = solve(inorder, postorder, inStart, inIdx-1, postStart, postStart + leftSize - 1, mp);
        root->right = solve(inorder, postorder, inIdx+1, inEnd, postEnd - rightSize, postEnd-1, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[inorder[i]] = i;
        }

        return solve(inorder, postorder, 0, n-1, 0, n-1, mp);
    }
};
