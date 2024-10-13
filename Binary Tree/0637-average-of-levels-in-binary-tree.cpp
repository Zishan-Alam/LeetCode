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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res; //for storing answer

        if(root == nullptr){
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            double sum = 0; // to calculate the average of the levels

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                sum = sum + node->val; // adding the node vales of each level

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(sum / size); //storing the average of the values
        }
        return res;
    }
};
