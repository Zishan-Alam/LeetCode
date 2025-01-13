//Recursive Approach
class Solution {
public:

    vector<int> preorderHelper(TreeNode* root, vector<int> &res){
        //base case
        if(root == nullptr){
            return res;
        }
        //NODE
        res.push_back(root->val);

        //LEFT
        preorderHelper(root->left, res);

        //RIGHT
        preorderHelper(root->right, res);

        return res;

    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        return preorderHelper(root, res);
    }
};

//Iterative Approach
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* node = st.top();
            int val = st.top()->val;
            st.pop();

            res.push_back(val);

            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return res;
    }
};
