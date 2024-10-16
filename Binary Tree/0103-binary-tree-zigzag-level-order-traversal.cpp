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

    vector<vector<int>> zigzagLevelOrderHelper(TreeNode* root, vector<vector<int>> &res){

        queue<TreeNode*> q;
        q.push(root);

        bool flag = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);

            for(int i=0; i<size; i++){
                TreeNode* node  = q.front();
                q.pop();

                level[flag ? i : size-i-1] = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            flag = !flag;
            res.push_back(level);
        }
        return res;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;
        if(!root) return res;

        return zigzagLevelOrderHelper(root, res);
    }
};
