class Solution {
public:

    typedef unsigned long long ll;

    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> que;
        que.push({root, 0});
        int maxWidth = 0;

        while(!que.empty()) {
            int n = que.size();

            int left  = que.front().second;
            int right = que.back().second;

            maxWidth = max(maxWidth, right-left+1);

            while(n--) {
                auto [node, idx] = que.front();
                que.pop();

                if(node->left)  que.push( {node->left, 2*idx+1} );
                if(node->right) que.push( {node->right, 2*idx+2} );
            }
        }
        return maxWidth;
    }
};
