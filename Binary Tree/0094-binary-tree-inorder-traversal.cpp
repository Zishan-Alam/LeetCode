//Recursive Approach
class Solution {
public:

    void solve(TreeNode* root, vector<int> &res) {
        if(!root) return;

        solve(root->left, res);
        res.push_back(root->val);
        solve(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;

        solve(root, res);
        return res;
    }
};

//Iterative Approach (2 Stacks)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};

        stack<TreeNode*> st;
        stack<bool> visited;

        st.push(root);
        visited.push(0);

        vector<int> res;

        while(!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();
            bool flag = visited.top();
            visited.pop();

            //First Time Visit
            if(flag == 0) {
                //Right
                if(temp->right) {
                    st.push(temp->right);
                    visited.push(0);
                }
                //Node
                st.push(temp);
                visited.push(1);
                //Left
                if(temp->left) {
                    st.push(temp->left);
                    visited.push(0);
                }
            }
            //Second Time Visite
            else{
                res.push_back(temp->val);
            }
        }
        return res;
    }
};
