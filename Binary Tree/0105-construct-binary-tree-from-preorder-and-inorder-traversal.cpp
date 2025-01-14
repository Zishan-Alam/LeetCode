//time complexity of this solution is O(n^2) in the worst case
//space complexity is O(h), where h is the height of the tree
class Solution {
public:

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
        if (start > end) return nullptr;

        int rootVal = preorder[idx]; // Take the current root value from preorder
        idx++; // Move to the next index in preorder

        TreeNode* root = new TreeNode(rootVal);

        // Find the index of rootVal in inorder
        int i = start;
        for (; i <= end; i++) {
            if (inorder[i] == rootVal) break;
        }

        // Recursively build the left and right subtrees
        root->left = solve(preorder, inorder, start, i - 1, idx);
        root->right = solve(preorder, inorder, i + 1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0; // Start index for preorder
        return solve(preorder, inorder, 0, preorder.size() - 1, idx);
    }
};

//TC : O(n);
//SC : O(n)
class Solution {
public:

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int &idx, unordered_map<int, int> &mp) {
        if(inStart > inEnd) return nullptr;

        int rootVal = preorder[idx];
        int inIdx = mp[rootVal];

        idx++;

        TreeNode* root = new TreeNode(rootVal);

        root->left  = solve(preorder, inorder, inStart, inIdx-1, idx, mp);
        root->right = solve(preorder, inorder, inIdx+1, inEnd, idx, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int idx = 0;

        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[inorder[i]] = i;
        }

        return solve(preorder, inorder, 0, n-1, idx, mp);
    }
};
