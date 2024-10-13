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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector< vector<int> > res;

        //base case
        if(root == nullptr){
            return res;
        }

        queue<TreeNode*> q; //queue to store the nodes
        q.push(root);

        while(!q.empty()){

            int size = q.size();
            vector<int> level; //vector to store the nodes at each level

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
  
            }
            res.push_back(level); //pushing each level vector to the res vector
        }

        reverse(res.begin(), res.end()); //reversing the original res vector will solve the requirement
        return res;
    }
};
