//DFS
//T.C : O(n)
//S.C : O(1) Auxiliary Space, O(depth) system stack space of recursion
class Solution {
public:
    TreeNode* add(TreeNode* root, int val, int depth, int curr) {
        if(!root) return nullptr;

        if(curr == depth - 1) {

            TreeNode* newLeft = root->left;
            TreeNode* newRight = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = newLeft;
            root->right->right = newRight;
        }

        root->left = add(root->left, val, depth, curr+1);
        root->right = add(root->right, val, depth, curr+1);

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        return add(root, val, depth, 1);
    }
};

//Using BFS
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        // If depth is 1, create a new root and attach the original tree to it
        if (d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }

        // Initialize a queue for level-order traversal
        queue<TreeNode*> que;
        que.push(root);

        int level = 0;
        bool rowAdded = false;

        // Level-order traversal to find the (d - 1)th level
        while (!que.empty()) {
            int n = que.size();
            level++;

            for (int i = 0; i < n; i++) {
                TreeNode* curr = que.front();
                que.pop();

                TreeNode* tempL = curr->left;
                TreeNode* tempR = curr->right;

                // Add a new row when the current level is (d - 1)
                if (level == d - 1) {
                    curr->left = new TreeNode(v);
                    curr->right = new TreeNode(v);

                    curr->left->left = tempL;
                    curr->right->right = tempR;

                    rowAdded = true;
                }

                // Push child nodes to the queue for further processing
                if (tempL) que.push(tempL);
                if (tempR) que.push(tempR);
            }

            // Break early if the new row has been added
            if (rowAdded) break;
        }

        return root;
    }
};
