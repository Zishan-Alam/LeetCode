//Recursive Approach
class Solution {
public:

    void solve(TreeNode* root, vector<int> &res) {
        if(!root) return;

        solve(root->left, res);
        solve(root->right, res);
        res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;

        solve(root, res);
        return res;
    }
};

//Iterative Approach
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* node = st.top();
            int val = st.top()->val;
            st.pop();

            res.push_back(val);

            if(node->left)  st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(begin(res), end(res));
        return res;
    }
};

